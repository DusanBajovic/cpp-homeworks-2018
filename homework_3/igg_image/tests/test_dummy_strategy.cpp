#include "igg_image/image.h"
#include "igg_image/io_strategies/dummy_strategy.h"
#include <gtest/gtest.h>


TEST(TestImage, WritingAndReadingUsingDummyStrategy) {
  igg::DummyIoStrategy strategy;
  igg::Image image(2, 2, strategy);
  bool read_result;

  image.at(0, 0) = {0, 0, 0};
  image.at(0, 1) = {1, 1, 1};

  image.at(1, 0) = {2, 2, 2};
  image.at(1, 1) = {3, 3, 3};

  image.WriteToDisk("../data/dummyname");
  read_result = image.ReadFromDisk("../data/dummyname");

  EXPECT_TRUE(read_result);
  EXPECT_EQ(0, image.rows());
  EXPECT_EQ(0, image.cols());
}