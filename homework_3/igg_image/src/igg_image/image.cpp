#include "image.h"

using namespace igg;

void Image::DownScale(int scale)
{
    int rows_new = rows_ / scale;
    int cols_new = cols_ / scale;
    std::vector<Pixel> data_new(rows_new * cols_new);
    int p_rows, p_cols;

    for (int i = 0; i < rows_new; ++i) {
    for (int j = 0; j < cols_new; ++j) {
        p_rows = i * scale;
        p_cols = j * scale;
        data_new[(j * cols_new) + i] = data_[(p_cols * cols_) + p_rows];
    }
    }

    rows_ = rows_new;
    cols_ = cols_new;
    data_ = data_new;
}

void Image::UpScale(int scale)
{
    int rows_new = rows_ * scale;
    int cols_new = cols_ * scale;
    std::vector<Pixel> data_new(rows_new * cols_new);
    int p_rows, p_cols;

    for (int i = 0; i < rows_new; ++i) {
        for (int j = 0; j < cols_new; ++j) {
            p_rows = i / scale;
            p_cols = j / scale;
            data_new[(j * cols_new) + i] = data_[(p_cols * cols_) + p_rows];
        }
    }

    rows_ = rows_new;
    cols_ = cols_new;
    data_ = data_new;
}

bool Image::ReadFromDisk(const std::string& file_name)
{
    ImageData image_data;

    image_data = io_strategy_.Read(file_name);

    if(image_data.data.empty())
    {   
        return false;
    }

    rows_ = image_data.rows;
    cols_ = image_data.cols;
    max_val_ = image_data.max_val;

    data_.resize(rows_*cols_);
 
    for(int i=0; i< rows_*cols_; ++i)
    {
        data_[i].red = image_data.data[0][i];     // copy red pixel
        data_[i].green = image_data.data[1][i];   // copy green pixel
        data_[i].blue = image_data.data[2][i];    // copy blue pixel
    }
    
    return true;  
}


void Image::WriteToDisk(const std::string &file_name) const
{
    ImageData image_data;

    image_data.rows = rows_;
    image_data.cols = cols_;
    image_data.max_val = max_val_;

    std::vector<int> red(image_data.rows * image_data.cols, 0);
    std::vector<int> green(image_data.rows * image_data.cols, 0);
    std::vector<int> blue(image_data.rows * image_data.cols, 0);
    image_data.data = {red, green, blue};

    for(int i=0; i< image_data.rows*image_data.cols; ++i)
    {
        image_data.data[0][i] = data_[i].red;     // copy red pixel
        image_data.data[1][i] = data_[i].green;   // copy blue pixel
        image_data.data[2][i] = data_[i].blue;    // copy green pixel
    }

    io_strategy_.Write(file_name, image_data);
}