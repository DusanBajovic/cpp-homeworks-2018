#pragma once

#include <memory>
#include <stdbool.h>
#include <stdio.h>
#include <string>
#include <vector>

#include "io_strategies/strategy.h"

namespace igg {

class Image {
public:
  /// A struct within class Image that defines a pixel.
  struct Pixel {
    int red;
    int green;
    int blue;
  };

  Image(void){}
  Image(int rows, int cols)
      : rows_{rows}, cols_{cols} {
    data_.resize(rows * cols, {0, 0, 0});
  }
  int rows() const { return rows_; }
  int cols() const { return cols_; }
  Pixel &at(int row, int col) { return data_.at(row * cols_ + col); }

  void SetIoStrategy(const std::shared_ptr<IoStrategy>& strategy_ptr)
  {
    io_strategy_ = strategy_ptr;
  }

  int ReadFromDisk(const std::string &file_name);
  int WriteToDisk(const std::string &file_name) const;

private:
  std::shared_ptr<IoStrategy> io_strategy_ = nullptr;

  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<Pixel> data_;
};

} // namespace igg
