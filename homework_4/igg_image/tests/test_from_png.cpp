#include "igg_image/image.h"
#include "igg_image/io_strategies/png_strategy.h"
#include <gtest/gtest.h>


TEST(TestImage, ReadingFromPNGFile) {
  std::shared_ptr<igg::IoStrategy> strategy = std::make_shared<igg::PngIoStrategy>();
  igg::Image image;
  image.SetIoStrategy(strategy);

  EXPECT_EQ(0, image.ReadFromDisk("../data/lenna.png"));

  EXPECT_EQ(512, image.rows());
  EXPECT_EQ(512, image.cols());

  EXPECT_EQ(185, image.at(511, 511).red);
  EXPECT_EQ(74, image.at(511, 511).green);
  EXPECT_EQ(81, image.at(511, 511).blue);
}

TEST(TestImage, WritingToPNGFiles) {
  std::shared_ptr<igg::IoStrategy> strategy = std::make_shared<igg::PngIoStrategy>();
  igg::Image image;
  image.SetIoStrategy(strategy);

  EXPECT_EQ(0, image.ReadFromDisk("../data/lenna.png"));
  EXPECT_EQ(0, image.WriteToDisk("../data/lenna_copy.png"));
}
