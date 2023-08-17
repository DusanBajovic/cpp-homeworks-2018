#include <gtest/gtest.h>
#include "igg_image/image.h"
#include "igg_image/io_strategies/dummy_strategy.h"


TEST(TestImage, CheckDownScaling)
{
    igg::DummyIoStrategy strategy;
    igg::Image image(4, 4, strategy);

    image.at(0, 0) = {0, 0, 0};
    image.at(0, 1) = {1, 1, 1};
    image.at(0, 2) = {2, 2, 2};
    image.at(0, 3) = {3, 3, 3};

    image.at(1, 0) = {4, 4, 4};
    image.at(1, 1) = {5, 5, 5};
    image.at(1, 2) = {6, 6, 6};
    image.at(1, 3) = {7, 7, 7};

    image.at(2, 0) = {8, 8, 8};
    image.at(2, 1) = {9, 9, 9};
    image.at(2, 2) = {10, 10, 10};
    image.at(2, 3) = {11, 11, 11};

    image.at(3, 0) = {12, 12, 12};
    image.at(3, 1) = {13, 13, 13};
    image.at(3, 2) = {14, 14, 14};
    image.at(3, 3) = {15, 15, 15};

    image.DownScale(2);

    EXPECT_EQ(2, image.rows());
    EXPECT_EQ(2, image.cols());

    EXPECT_EQ(0, image.at(0, 0).red);
    EXPECT_EQ(0, image.at(0, 0).green);
    EXPECT_EQ(0, image.at(0, 0).blue);

    EXPECT_EQ(2, image.at(0, 1).red);
    EXPECT_EQ(2, image.at(0, 1).green);
    EXPECT_EQ(2, image.at(0, 1).blue);

    EXPECT_EQ(8, image.at(1, 0).red);
    EXPECT_EQ(8, image.at(1, 0).green);
    EXPECT_EQ(8, image.at(1, 0).blue);

    EXPECT_EQ(10, image.at(1, 1).red);
    EXPECT_EQ(10, image.at(1, 1).green);
    EXPECT_EQ(10, image.at(1, 1).blue);
}

TEST(TestImage, CheckUScaling)
{
    igg::DummyIoStrategy strategy;
    igg::Image image(2, 2, strategy);

    image.at(0, 0) = {0, 0, 0};
    image.at(0, 1) = {1, 1, 1};

    image.at(1, 0) = {2, 2, 2};
    image.at(1, 1) = {3, 3, 3};

    image.UpScale(2);

    EXPECT_EQ(4, image.rows());
    EXPECT_EQ(4, image.cols());

    EXPECT_EQ(0, image.at(0, 0).red);
    EXPECT_EQ(0, image.at(0, 0).green);
    EXPECT_EQ(0, image.at(0, 0).blue);

    EXPECT_EQ(0, image.at(0, 1).red);
    EXPECT_EQ(0, image.at(0, 1).green);
    EXPECT_EQ(0, image.at(0, 1).blue);

    EXPECT_EQ(1, image.at(0, 2).red);
    EXPECT_EQ(1, image.at(0, 2).green);
    EXPECT_EQ(1, image.at(0, 2).blue);

    EXPECT_EQ(1, image.at(0, 3).red);
    EXPECT_EQ(1, image.at(0, 3).green);
    EXPECT_EQ(1, image.at(0, 3).blue);

    EXPECT_EQ(0, image.at(1, 0).red);
    EXPECT_EQ(0, image.at(1, 0).green);
    EXPECT_EQ(0, image.at(1, 0).blue);

    EXPECT_EQ(0, image.at(1, 1).red);
    EXPECT_EQ(0, image.at(1, 1).green);
    EXPECT_EQ(0, image.at(1, 1).blue);

    EXPECT_EQ(1, image.at(1, 2).red);
    EXPECT_EQ(1, image.at(1, 2).green);
    EXPECT_EQ(1, image.at(1, 2).blue);

    EXPECT_EQ(1, image.at(1, 3).red);
    EXPECT_EQ(1, image.at(1, 3).green);
    EXPECT_EQ(1, image.at(1, 3).blue);

    EXPECT_EQ(2, image.at(2, 0).red);
    EXPECT_EQ(2, image.at(2, 0).green);
    EXPECT_EQ(2, image.at(2, 0).blue);

    EXPECT_EQ(2, image.at(2, 1).red);
    EXPECT_EQ(2, image.at(2, 1).green);
    EXPECT_EQ(2, image.at(2, 1).blue);

    EXPECT_EQ(3, image.at(2, 2).red);
    EXPECT_EQ(3, image.at(2, 2).green);
    EXPECT_EQ(3, image.at(2, 2).blue);

    EXPECT_EQ(3, image.at(2, 3).red);
    EXPECT_EQ(3, image.at(2, 3).green);
    EXPECT_EQ(3, image.at(2, 3).blue);

    EXPECT_EQ(2, image.at(3, 0).red);
    EXPECT_EQ(2, image.at(3, 0).green);
    EXPECT_EQ(2, image.at(3, 0).blue);

    EXPECT_EQ(2, image.at(3, 1).red);
    EXPECT_EQ(2, image.at(3, 1).green);
    EXPECT_EQ(2, image.at(3, 1).blue);

    EXPECT_EQ(3, image.at(3, 2).red);
    EXPECT_EQ(3, image.at(3, 2).green);
    EXPECT_EQ(3, image.at(3, 2).blue);

    EXPECT_EQ(3, image.at(3, 3).red);
    EXPECT_EQ(3, image.at(3, 3).green);
    EXPECT_EQ(3, image.at(3, 3).blue);
}