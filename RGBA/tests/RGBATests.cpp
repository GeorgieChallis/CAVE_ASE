#include <gtest/gtest.h>
#include "RGBA.h"

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}

//TEST (GROUP, test_name){}
TEST(RGBA, construct)
{
  RGBA pixel;
  /*ASSERT_TRUE(pixel.r == 0);
  ASSERT_TRUE(pixel.g == 0);
  ASSERT_TRUE(pixel.b == 0);
  ASSERT_TRUE(pixel.a == 0);*/

}

TEST(RGBA, userCtor)
{
  RGBA pixel(255, 100, 22, 128);
  ASSERT_EQ(pixel.r, 255);
  ASSERT_EQ(pixel.g, 100);
  ASSERT_EQ(pixel.b, 22);
  ASSERT_EQ(pixel.a, 128);
}

TEST(RGBA, copy)
{
  RGBA p1(1,2,3,4);
  auto p2 = p1;
  ASSERT_TRUE(p1.r = p2.r);
}