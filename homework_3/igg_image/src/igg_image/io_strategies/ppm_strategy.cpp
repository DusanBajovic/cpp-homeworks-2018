// Copyright Dusan Bajovic, year 2023.

#include "igg_image/io_strategies/ppm_strategy.h"

#include <fstream>
#include <iomanip>
#include <sstream>
#include <stdbool.h>
#include <string>
#include <vector>


namespace igg {

bool PpmIoStrategy::Write(const std::string &file_name,
                          const ImageData &data) const {
  std::ofstream image(file_name);

  image << "P3" << std::endl;
  image << "  " << data.rows << "  ";
  image << "  " << data.cols << std::endl;
  image << "  " << data.max_val << std::endl;

  for (int i = 0; i < data.rows * data.cols; ++i) {

    image << "  " << std::setw(3) << data.data[0][i] << "  " << std::setw(3)
          << data.data[1][i] << "  " << std::setw(3) << data.data[2][i];

    if (i % 4 == 3) // after 4 pixels move to next line
    {
      image << std::endl;
    }
  }

  return true;
}

ImageData PpmIoStrategy::Read(const std::string &file_name) const {
  std::ifstream image(file_name);
  std::string line;
  std::stringstream line_stream;
  ImageData image_data;

  if (!image) {
    image_data.rows = 0;
    image_data.cols = 0;
    image_data.max_val = 0;
    image_data.data.clear();
    return image_data;
  }

  std::getline(image, line);
  if (line != "P3") {
    image_data.rows = 0;
    image_data.cols = 0;
    image_data.max_val = 0;
    image_data.data.clear();
    return image_data;
  }

  std::getline(image, line); // skip all comments
  while (line[0] == '#') {
    std::getline(image, line);
  }

  line_stream.str(line);
  line_stream >> image_data.rows >> image_data.cols;
  line_stream.clear();

  std::getline(image, line); // skip all comments
  while (line[0] == '#') {
    std::getline(image, line);
  }

  line_stream.str(line);
  line_stream >> image_data.max_val;
  line_stream.clear();

  std::vector<int> red(image_data.rows * image_data.cols, 0);
  std::vector<int> green(image_data.rows * image_data.cols, 0);
  std::vector<int> blue(image_data.rows * image_data.cols, 0);

  for (int i = 0; i < image_data.rows * image_data.cols; ++i) {
    image >> red[i] >> green[i] >> blue[i];
  }

  image_data.data = {red, green, blue};
  return image_data;
}

} // namespace igg
