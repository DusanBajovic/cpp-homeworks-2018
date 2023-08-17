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