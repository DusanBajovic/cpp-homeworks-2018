#include "igg_image/image.h"
#include "igg_image/io_strategies/ppm_strategy.h"
#include <gtest/gtest.h>


TEST(TestImage, ReadingFromPPMFile) {
  igg::PpmIoStrategy strategy;
  igg::Image image(strategy);
  bool read_result;

  read_result = image.ReadFromDisk("../data/pbmlib.ascii.ppm");

  EXPECT_EQ(true, read_result);
  EXPECT_EQ(300, image.rows());
  EXPECT_EQ(300, image.cols());

  EXPECT_EQ(255, image.at(0, 0).red);
  EXPECT_EQ(150, image.at(0, 0).green);
  EXPECT_EQ(250, image.at(0, 0).blue);

  EXPECT_EQ(255, image.at(299, 299).red);
  EXPECT_EQ(150, image.at(299, 299).green);
  EXPECT_EQ(255, image.at(299, 299).blue);
}

TEST(TestImage, WritingToPPMFiles) {
  igg::PpmIoStrategy strategy;
  igg::Image image(strategy);
  bool read_result;

  read_result = image.ReadFromDisk("../data/pbmlib.ascii.ppm");
  image.WriteToDisk("../data/pbmlib.ascii_copy.ppm");

  EXPECT_EQ(true, read_result);
}

TEST(TestImage, WritingAndReadingToPPMFiles) {
  igg::PpmIoStrategy strategy;
  igg::Image write_image(4, 4, strategy);
  igg::Image read_image(strategy);
  bool read_result;

  write_image.at(0, 0) = {0, 0, 0};
  write_image.at(0, 1) = {1, 1, 1};
  write_image.at(0, 2) = {2, 2, 2};
  write_image.at(0, 3) = {3, 3, 3};

  write_image.at(1, 0) = {4, 4, 4};
  write_image.at(1, 1) = {5, 5, 5};
  write_image.at(1, 2) = {6, 6, 6};
  write_image.at(1, 3) = {7, 7, 7};

  write_image.at(2, 0) = {8, 8, 8};
  write_image.at(2, 1) = {9, 9, 9};
  write_image.at(2, 2) = {10, 10, 10};
  write_image.at(2, 3) = {11, 11, 11};

  write_image.at(3, 0) = {12, 12, 12};
  write_image.at(3, 1) = {13, 13, 13};
  write_image.at(3, 2) = {14, 14, 14};
  write_image.at(3, 3) = {15, 15, 15};

  write_image.WriteToDisk("../data/custom.ppm");
  read_result = read_image.ReadFromDisk("../data/custom.ppm");

  EXPECT_TRUE(read_result);
  EXPECT_EQ(4, read_image.rows());
  EXPECT_EQ(4, read_image.cols());

  EXPECT_EQ(0, read_image.at(0, 0).red);
  EXPECT_EQ(0, read_image.at(0, 0).green);
  EXPECT_EQ(0, read_image.at(0, 0).blue);

  EXPECT_EQ(1, read_image.at(0, 1).red);
  EXPECT_EQ(1, read_image.at(0, 1).green);
  EXPECT_EQ(1, read_image.at(0, 1).blue);

  EXPECT_EQ(2, read_image.at(0, 2).red);
  EXPECT_EQ(2, read_image.at(0, 2).green);
  EXPECT_EQ(2, read_image.at(0, 2).blue);

  EXPECT_EQ(3, read_image.at(0, 3).red);
  EXPECT_EQ(3, read_image.at(0, 3).green);
  EXPECT_EQ(3, read_image.at(0, 3).blue);

  EXPECT_EQ(4, read_image.at(1, 0).red);
  EXPECT_EQ(4, read_image.at(1, 0).green);
  EXPECT_EQ(4, read_image.at(1, 0).blue);

  EXPECT_EQ(5, read_image.at(1, 1).red);
  EXPECT_EQ(5, read_image.at(1, 1).green);
  EXPECT_EQ(5, read_image.at(1, 1).blue);

  EXPECT_EQ(6, read_image.at(1, 2).red);
  EXPECT_EQ(6, read_image.at(1, 2).green);
  EXPECT_EQ(6, read_image.at(1, 2).blue);

  EXPECT_EQ(7, read_image.at(1, 3).red);
  EXPECT_EQ(7, read_image.at(1, 3).green);
  EXPECT_EQ(7, read_image.at(1, 3).blue);

  EXPECT_EQ(8, read_image.at(2, 0).red);
  EXPECT_EQ(8, read_image.at(2, 0).green);
  EXPECT_EQ(8, read_image.at(2, 0).blue);

  EXPECT_EQ(9, read_image.at(2, 1).red);
  EXPECT_EQ(9, read_image.at(2, 1).green);
  EXPECT_EQ(9, read_image.at(2, 1).blue);

  EXPECT_EQ(10, read_image.at(2, 2).red);
  EXPECT_EQ(10, read_image.at(2, 2).green);
  EXPECT_EQ(10, read_image.at(2, 2).blue);

  EXPECT_EQ(11, read_image.at(2, 3).red);
  EXPECT_EQ(11, read_image.at(2, 3).green);
  EXPECT_EQ(11, read_image.at(2, 3).blue);

  EXPECT_EQ(12, read_image.at(3, 0).red);
  EXPECT_EQ(12, read_image.at(3, 0).green);
  EXPECT_EQ(12, read_image.at(3, 0).blue);

  EXPECT_EQ(13, read_image.at(3, 1).red);
  EXPECT_EQ(13, read_image.at(3, 1).green);
  EXPECT_EQ(13, read_image.at(3, 1).blue);

  EXPECT_EQ(14, read_image.at(3, 2).red);
  EXPECT_EQ(14, read_image.at(3, 2).green);
  EXPECT_EQ(14, read_image.at(3, 2).blue);

  EXPECT_EQ(15, read_image.at(3, 3).red);
  EXPECT_EQ(15, read_image.at(3, 3).green);
  EXPECT_EQ(15, read_image.at(3, 3).blue);
}