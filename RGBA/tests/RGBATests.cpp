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
  ASSERT_TRUE(pixel.r == 0);
  ASSERT_TRUE(pixel.g == 0);
  ASSERT_TRUE(pixel.b == 0);
  ASSERT_TRUE(pixel.a == 0);

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
  ASSERT_TRUE(p1.g = p2.g);
  ASSERT_TRUE(p1.b = p2.b);
  ASSERT_TRUE(p1.a = p2.a);
}

TEST(RGBA, setRGBA)
{
  RGBA px;
  px.setRGBA(10, 100, 200, 255);
  ASSERT_EQ(px.r, 10);
  ASSERT_EQ(px.g, 100);
  ASSERT_EQ(px.b, 200);
  ASSERT_EQ(px.a, 255);
}

TEST(RGBA, clamp)
{
  unsigned char max = 255;
  unsigned char min = 0;
  
  RGBA px;
  px.setRGBA(-1, 0, 256, 500);
  px.clamp(min, max);
  ASSERT_EQ(px.r, 0);
  ASSERT_EQ(px.g, 0);
  ASSERT_EQ(px.b, 255);
  ASSERT_EQ(px.a, 255);
}