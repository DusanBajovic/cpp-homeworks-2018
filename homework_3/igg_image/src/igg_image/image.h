// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <stdio.h>
#include <stdbool.h>
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

  // TODO: fill public interface.
  Image(const IoStrategy &io_strategy) : io_strategy_{io_strategy} {}
  Image(int rows, int cols, const IoStrategy &io_strategy)
      : io_strategy_(io_strategy), rows_{rows}, cols_{cols} {
    data_.resize(rows * cols, {0, 0, 0});
  }
  int rows() const { return rows_; }
  int cols() const { return cols_; }
  Pixel &at(int row, int col) { return data_.at(row * cols_ + col); }

private:
  // TODO: add missing private members when needed.
  const IoStrategy &io_strategy_;

  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<Pixel> data_;
};

} // namespace igg
