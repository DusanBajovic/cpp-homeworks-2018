#include <gtest/gtest.h>
#include "igg_image/image.h"
#include "igg_image/io_strategies/dummy_strategy.h"

TEST(TestImage, Constructor)
{
    igg::DummyIoStrategy strategy;
    igg::Image image(strategy);

    EXPECT_EQ(0, image.rows());
    EXPECT_EQ(0, image.cols());
}