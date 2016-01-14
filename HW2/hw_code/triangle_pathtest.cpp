#include "triangle.h"
#include "gtest/gtest.h"

TEST(triangle, C0) {
		EXPECT_EQ("OUT_OF_RANGE", triangle(0, 100, 100));
    EXPECT_EQ("ISOSCELES", triangle(1, 100, 100));
    EXPECT_EQ("EQUILATERAL", triangle(100, 100, 100));
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(200, 100, 100));
    EXPECT_EQ("SCALENE", triangle(100, 101, 102));
}

TEST(triangle, C1) {
		EXPECT_EQ("OUT_OF_RANGE", triangle(0, 100, 100));
    EXPECT_EQ("ISOSCELES", triangle(1, 100, 100));
    EXPECT_EQ("EQUILATERAL", triangle(100, 100, 100));
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(200, 100, 100));
    EXPECT_EQ("SCALENE", triangle(100, 101, 102));
}

TEST(triangle, C2) {
		EXPECT_EQ("OUT_OF_RANGE", triangle(0, 100, 100));
    EXPECT_EQ("ISOSCELES", triangle(1, 100, 100));
    EXPECT_EQ("EQUILATERAL", triangle(100, 100, 100));
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(200, 100, 100));
    EXPECT_EQ("SCALENE", triangle(100, 101, 102));
}

TEST(triangle, MCDC) {

		/*First if*/
		//T, F, T, F, T, F
		EXPECT_EQ("OUT_OF_RANGE", triangle(201, 201, 201));
		//T, F, T, F, F, T
		EXPECT_EQ("OUT_OF_RANGE", triangle(201, 201, 0));
		//T, F, T, F, F, F 
		EXPECT_EQ("OUT_OF_RANGE", triangle(201, 201, 100));

		//T, F, F, T, T, F
		EXPECT_EQ("OUT_OF_RANGE", triangle(201, 0, 201));
		//T, F, F, T, F, T
		EXPECT_EQ("OUT_OF_RANGE", triangle(201, 0, 0));
		//T, F, F, T, F, F 
		EXPECT_EQ("OUT_OF_RANGE", triangle(201, 0, 100));

		//T, F, F, F, T, F
		EXPECT_EQ("OUT_OF_RANGE", triangle(201, 100, 201));
		//T, F, F, F, F, T
		EXPECT_EQ("OUT_OF_RANGE", triangle(201, 100, 0));
		//T, F, F, F, F, F 
		EXPECT_EQ("OUT_OF_RANGE", triangle(201, 100, 100));

		//F, T, T, F, T, F
		EXPECT_EQ("OUT_OF_RANGE", triangle(0, 201, 201));
		//F, T, T, F, F, T
		EXPECT_EQ("OUT_OF_RANGE", triangle(0, 201, 0));	
		//F, T, T, F, F, F 
		EXPECT_EQ("OUT_OF_RANGE", triangle(0, 201, 100));	

		//F, T, F, T, T, F
		EXPECT_EQ("OUT_OF_RANGE", triangle(0, 0, 201));
		//F, T, F, T, F, T
		EXPECT_EQ("OUT_OF_RANGE", triangle(0, 0, 0));	
		//F, T, F, T, F, F 
		EXPECT_EQ("OUT_OF_RANGE", triangle(0, 0, 100));	

		//F, T, F, F, T, F
		EXPECT_EQ("OUT_OF_RANGE", triangle(0, 100, 201));
		//F, T, F, F, F, T
		EXPECT_EQ("OUT_OF_RANGE", triangle(0, 100, 0));	
		//F, T, F, F, F, F 
		EXPECT_EQ("OUT_OF_RANGE", triangle(0, 100, 100));	
	
		//F, F, T, F, T, F
		EXPECT_EQ("OUT_OF_RANGE", triangle(100, 201, 201));
		//F, F, T, F, F, T
		EXPECT_EQ("OUT_OF_RANGE", triangle(100, 201, 0));	
		//F, F, T, F, F, F 
		EXPECT_EQ("OUT_OF_RANGE", triangle(100, 201, 100));	

		//F, F, F, T, T, F
		EXPECT_EQ("OUT_OF_RANGE", triangle(100, 0, 201));
		//F, F, F, T, F, T
		EXPECT_EQ("OUT_OF_RANGE", triangle(100, 0, 0));	
		//F, F, F, T, F, F 
		EXPECT_EQ("OUT_OF_RANGE", triangle(100, 0, 100));	

		//F, F, F, F, T, F
		EXPECT_EQ("OUT_OF_RANGE", triangle(100, 100, 201));
		//F, F, F, F, F, T
		EXPECT_EQ("OUT_OF_RANGE", triangle(100, 100, 0));	
		//F, F, F, F, F, F 
		EXPECT_EQ("EQUILATERAL", triangle(100, 100, 100));	

		/*second if*/
		//T, T
		EXPECT_EQ("EQUILATERAL", triangle(100, 100, 100));	
		//T, F 
		EXPECT_EQ("ISOSCELES", triangle(100, 100, 50));	
		//F, T
		EXPECT_EQ("ISOSCELES", triangle(50, 100, 100));	
		//F, F 
		EXPECT_EQ("SCALENE", triangle(101, 102, 103));	

		/*third if*/
		//T, T, T
		EXPECT_EQ("SCALENE", triangle(101, 102, 103));
		//T, T, F
		EXPECT_EQ("NOT_A_TRIANGLE", triangle(101, 1, 2));
		//T, F, T
		EXPECT_EQ("NOT_A_TRIANGLE", triangle(1, 100, 2));
		//F, T, T
		EXPECT_EQ("NOT_A_TRIANGLE", triangle(1, 2, 100));

		/*fourth if*/
		//T, F, F
		EXPECT_EQ("ISOSCELES", triangle(100, 100, 50));	
		//F, T, F
		EXPECT_EQ("ISOSCELES", triangle(50, 100, 100));	
		//F, F, T	
		EXPECT_EQ("ISOSCELES", triangle(100, 50, 100));	
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
  std::string filter = argv[1];
  if(filter.compare("MCDC") != 0) {
    ::testing::GTEST_FLAG(filter) = "*.C" + filter;
  }
  else {
    ::testing::GTEST_FLAG(filter) = "*." + filter;
  }
  return RUN_ALL_TESTS();
}
