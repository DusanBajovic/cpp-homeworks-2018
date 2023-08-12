#include "image.h"
#include "io_tools.h"
#include <iostream>


using namespace igg;

bool Image::FillFromPgm(const std::string &file_name) {
  igg::io_tools::ImageData readImageData;

  readImageData = igg::io_tools::ReadFromPgm(file_name);

  if (readImageData.data.empty()) {
    return false;
  }

  rows_ = readImageData.rows;
  cols_ = readImageData.cols;
  max_val_ = readImageData.max_val;

  copy(readImageData.data.begin(), readImageData.data.end(),
       back_inserter(data_));

  return true;
}

void Image::WriteToPgm(const std::string &file_name) const {
  igg::io_tools::ImageData writeImageData;

  writeImageData.rows = rows_;
  writeImageData.cols = cols_;
  writeImageData.max_val = max_val_;
  writeImageData.data = data_;

  if (igg::io_tools::WriteToPgm(writeImageData, file_name) == false) {
    std::cout << "Image data is not written!!!" << std::endl;
  }
}

std::vector<float> Image::ComputeHistogram(int bins) const {
  std::vector<float> histogram(bins);
  int bin_number = 0;

  if (bins < max_val_) {
    for (bin_number = 0; bin_number < bins; ++bin_number) {
      histogram[bin_number] = 0;
      for (const int &eachPixel : data_) {
        if ((eachPixel >= (bin_number * max_val_ / bins)) &&
            (eachPixel < ((bin_number + 1) * max_val_ / bins))) {
          histogram[bin_number] += 1;
        }
      }
      histogram[bin_number] /= (rows_ * cols_);
    }
  }

  return histogram;
}

void Image::DownScale(int scale) {
  int rows_new = rows_ / scale;
  int cols_new = cols_ / scale;
  std::vector<int> data_new(rows_new * cols_new);
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
  data_.resize(rows_ * cols_);
  data_ = data_new;
}

void Image::UpScale(int scale) {
  int rows_new = rows_ * scale;
  int cols_new = cols_ * scale;
  std::vector<int> data_new(rows_new * cols_new);
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
  data_.resize(rows_ * cols_);
  data_ = data_new;
}