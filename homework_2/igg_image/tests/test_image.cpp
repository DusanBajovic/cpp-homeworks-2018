#include <gtest/gtest.h>

#include "igg_image/image.h"

using namespace igg;

Image image(4, 4);

TEST(TestImage, FirstTest)
{
    EXPECT_EQ(4, image.rows());
}