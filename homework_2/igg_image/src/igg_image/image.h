#pragma once

#include <vector>

namespace igg {

class Image {
 public:
  ///////////////////// Create the public interface here ///////////////////////
  Image();
  Image(int rows, int cols) : rows_{rows}, cols_{cols} {
    data_.reserve(rows*cols);
  }
  int rows() const {return rows_;}
  int cols() const {return cols_;}
  int& at(const int row, const int col) {
    return data_.at(row*cols_ + col -1);
  }
 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
};

}  // namespace igg
