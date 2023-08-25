#include "igg_image/image.h"
#include "igg_image/io_strategies/dummy_strategy.h"
#include <gtest/gtest.h>


TEST(TestImage, WritingAndReadingUsingDummyStrategy) {
  std::shared_ptr<igg::IoStrategy> strategy = std::make_shared<igg::DummyIoStrategy>();
  igg::Image image(2, 2);
  image.SetIoStrategy(strategy);

  image.at(0, 0) = {0, 0, 0};
  image.at(0, 1) = {1, 1, 1};

  image.at(1, 0) = {2, 2, 2};
  image.at(1, 1) = {3, 3, 3};


  EXPECT_EQ(0, image.WriteToDisk("../data/dummyname"));
  EXPECT_EQ(0, image.ReadFromDisk("../data/dummyname"));
  EXPECT_EQ(0, image.rows());
  EXPECT_EQ(0, image.cols());
}