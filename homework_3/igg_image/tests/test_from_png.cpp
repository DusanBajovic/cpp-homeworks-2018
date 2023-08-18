#include <gtest/gtest.h>
#include "igg_image/image.h"
#include "igg_image/io_strategies/png_strategy.h"

TEST(TestImage, ReadingFromPNGFile)
{
    igg::PngIoStrategy strategy;
    igg::Image image(strategy);
    bool read_result;

    read_result = image.ReadFromDisk("../data/lenna.png");

    EXPECT_EQ(true, read_result);
    EXPECT_EQ(512, image.rows());
    EXPECT_EQ(512, image.cols());

    EXPECT_EQ(185, image.at(511, 511).red);
    EXPECT_EQ(74, image.at(511, 511).green);
    EXPECT_EQ(81, image.at(511, 511).blue);
}

TEST(TestImage, WritingToPNGFiles)
{
    igg::PngIoStrategy strategy;
    igg::Image image(strategy);
    bool read_result;

    read_result = image.ReadFromDisk("../data/lenna.png");
    image.WriteToDisk("../data/lenna_copy.png");
    
    EXPECT_EQ(true, read_result);
}

TEST(TestImage, WritingToPNGFilesWithDownScaling)
{
    igg::PngIoStrategy strategy;
    igg::Image image(strategy);
    bool read_result;

    read_result = image.ReadFromDisk("../data/lenna.png");
    EXPECT_EQ(true, read_result);
    EXPECT_EQ(512, image.rows());
    EXPECT_EQ(512, image.cols());

    EXPECT_EQ(181, image.at(510, 510).red);
    EXPECT_EQ(71, image.at(510, 510).green);
    EXPECT_EQ(81, image.at(510, 510).blue);

    image.DownScale(2);
    image.WriteToDisk("../data/lenna_down_scaled.png");
    EXPECT_EQ(256, image.rows());
    EXPECT_EQ(256, image.cols());

    EXPECT_EQ(181, image.at(255, 255).red);
    EXPECT_EQ(71, image.at(255, 255).green);
    EXPECT_EQ(81, image.at(255, 255).blue);
}

TEST(TestImage, WritingToPNGFilesWithUpScaling)
{
    igg::PngIoStrategy strategy;
    igg::Image image(strategy);
    bool read_result;

    read_result = image.ReadFromDisk("../data/lenna.png");
    EXPECT_EQ(true, read_result);
    EXPECT_EQ(512, image.rows());
    EXPECT_EQ(512, image.cols());

    EXPECT_EQ(185, image.at(511, 511).red);
    EXPECT_EQ(74, image.at(511, 511).green);
    EXPECT_EQ(81, image.at(511, 511).blue);

    image.UpScale(2);
    image.WriteToDisk("../data/lenna_up_scaled.png");
    EXPECT_EQ(1024, image.rows());
    EXPECT_EQ(1024, image.cols());

    EXPECT_EQ(185, image.at(1023, 1023).red);
    EXPECT_EQ(74, image.at(1023, 1023).green);
    EXPECT_EQ(81, image.at(1023, 1023).blue);
}

