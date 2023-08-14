#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <string>
#include <vector>

namespace igg {

class Image {
public:
  ///////////////////// Create the public interface here ///////////////////////
  Image(){}
  Image(int rows, int cols) : rows_{rows}, cols_{cols} {
    data_.resize(rows * cols, 0);
  }
  int rows() const { return rows_; }
  int cols() const { return cols_; }
  int &at(const int row, const int col) { return data_.at(row * cols_ + col); }
  bool FillFromPgm(const std::string &file_name);
  void WriteToPgm(const std::string &file_name) const;
  std::vector<float> ComputeHistogram(int bins) const;
  void DownScale(int scale);
  void UpScale(int scale);

private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
};

} // namespace igg
