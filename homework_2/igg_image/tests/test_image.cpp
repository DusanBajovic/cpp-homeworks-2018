#include <gtest/gtest.h>

#include "igg_image/image.h"

using namespace igg;

Image image(4, 4);
Image lena;

TEST(TestImage, Getters) {
  EXPECT_EQ(4, image.rows());
  EXPECT_EQ(4, image.cols());
}

TEST(TestImage, At) {
  image.at(0, 0) = 0;
  image.at(0, 1) = 1;
  image.at(0, 2) = 2;
  image.at(0, 3) = 3;

  image.at(1, 0) = 4;
  image.at(1, 1) = 5;
  image.at(1, 2) = 6;
  image.at(1, 3) = 7;

  image.at(2, 0) = 208;
  image.at(2, 1) = 209;
  image.at(2, 2) = 210;
  image.at(2, 3) = 211;

  image.at(3, 0) = 212;
  image.at(3, 1) = 213;
  image.at(3, 2) = 214;
  image.at(3, 3) = 215;

  EXPECT_EQ(0, image.at(0, 0));
  EXPECT_EQ(1, image.at(0, 1));
  EXPECT_EQ(2, image.at(0, 2));
  EXPECT_EQ(3, image.at(0, 3));
  EXPECT_EQ(4, image.at(1, 0));
  EXPECT_EQ(5, image.at(1, 1));
  EXPECT_EQ(6, image.at(1, 2));
  EXPECT_EQ(7, image.at(1, 3));
  EXPECT_EQ(208, image.at(2, 0));
  EXPECT_EQ(209, image.at(2, 1));
  EXPECT_EQ(210, image.at(2, 2));
  EXPECT_EQ(211, image.at(2, 3));
  EXPECT_EQ(212, image.at(3, 0));
  EXPECT_EQ(213, image.at(3, 1));
  EXPECT_EQ(214, image.at(3, 2));
  EXPECT_EQ(215, image.at(3, 3));
}

TEST(TestImage, FileReading) {
  EXPECT_TRUE(lena.FillFromPgm("../data/lena.ascii.pgm"));
  EXPECT_EQ(512, lena.rows());
  EXPECT_EQ(512, lena.cols());
  EXPECT_EQ(43, lena.at(200, 230));
  EXPECT_EQ(162, lena.at(0, 0));
  EXPECT_EQ(107, lena.at(511, 511));
}

TEST(TestImage, WrongFileReading) {
  Image no_image;

  EXPECT_FALSE(no_image.FillFromPgm("../data/lena.pgm"));
}

TEST(TestImage, ImageHistogram2Bins) {
  std::vector<float> histogram = image.ComputeHistogram(2);

  EXPECT_EQ(2, histogram.size());
  EXPECT_EQ(1, histogram[0] + histogram[1]);
  EXPECT_EQ(0.5, histogram[0]);
  EXPECT_EQ(0.5, histogram[1]);
}

TEST(TestImage, ImageHistogram3Bins) {
  std::vector<float> histogram = image.ComputeHistogram(3);

  EXPECT_EQ(3, histogram.size());
  EXPECT_EQ(1, histogram[0] + histogram[1] + histogram[2]);
  EXPECT_EQ(0.5, histogram[0]);
  EXPECT_EQ(0.0, histogram[1]);
  EXPECT_EQ(0.5, histogram[2]);
}

TEST(TestImage, ImageHistogramLena) {
  std::vector<float> histogram = lena.ComputeHistogram(7);

  EXPECT_EQ(7, histogram.size());
  EXPECT_EQ(1, histogram[0] + histogram[1] + histogram[2] + histogram[3] +
                   histogram[4] + histogram[5] + histogram[6]);
}

TEST(TestImage, ImageDownScale) {
  image.DownScale(2);

  EXPECT_EQ(2, image.rows());
  EXPECT_EQ(2, image.cols());

  EXPECT_EQ(0, image.at(0, 0));
  EXPECT_EQ(2, image.at(0, 1));
  EXPECT_EQ(208, image.at(1, 0));
  EXPECT_EQ(210, image.at(1, 1));
}

TEST(TestImage, ImageDownScaleLena) {
  lena.DownScale(8);

  EXPECT_EQ(64, lena.rows());
  EXPECT_EQ(64, lena.cols());
}

TEST(TestImage, ImageUpScale) {
  image.UpScale(2);

  EXPECT_EQ(4, image.rows());
  EXPECT_EQ(4, image.cols());

  EXPECT_EQ(0, image.at(0, 0));
  EXPECT_EQ(0, image.at(0, 1));
  EXPECT_EQ(0, image.at(1, 0));
  EXPECT_EQ(0, image.at(1, 1));

  EXPECT_EQ(2, image.at(0, 2));
  EXPECT_EQ(2, image.at(0, 3));
  EXPECT_EQ(2, image.at(1, 2));
  EXPECT_EQ(2, image.at(1, 3));

  EXPECT_EQ(208, image.at(2, 0));
  EXPECT_EQ(208, image.at(2, 1));
  EXPECT_EQ(208, image.at(3, 0));
  EXPECT_EQ(208, image.at(3, 1));

  EXPECT_EQ(210, image.at(2, 2));
  EXPECT_EQ(210, image.at(2, 3));
  EXPECT_EQ(210, image.at(3, 2));
  EXPECT_EQ(210, image.at(3, 3));
}

TEST(TestImage, ImageUpScaleLena) {
  lena.UpScale(2);

  EXPECT_EQ(128, lena.rows());
  EXPECT_EQ(128, lena.cols());
}



