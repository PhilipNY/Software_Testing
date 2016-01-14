#include "commission.h"
#include "gtest/gtest.h"

TEST(commission, C0) {
    EXPECT_EQ("STOP_PROGRAM", commission(-1, 40, 45));
    EXPECT_EQ("INVALID_INPUT", commission(-2, 40, 45));
    EXPECT_EQ("334.0", commission(1, 40, 45));
		EXPECT_EQ("140.5", commission(1, 40, 1));
		EXPECT_EQ("10.0", commission(1, 1, 1));
}

TEST(commission, C1) {
    EXPECT_EQ("STOP_PROGRAM", commission(-1, 40, 45));
    EXPECT_EQ("INVALID_INPUT", commission(-2, 40, 45));
    EXPECT_EQ("334.0", commission(1, 40, 45));
		EXPECT_EQ("140.5", commission(1, 40, 1));
		EXPECT_EQ("10.0", commission(1, 1, 1));
}

TEST(commission, C2) {
    EXPECT_EQ("STOP_PROGRAM", commission(-1, 40, 45));
    EXPECT_EQ("INVALID_INPUT", commission(-2, 40, 45));
    EXPECT_EQ("334.0", commission(1, 40, 45));
		EXPECT_EQ("140.5", commission(1, 40, 1));
		EXPECT_EQ("10.0", commission(1, 1, 1));
}

TEST(commission, MCDC) {
		EXPECT_EQ("STOP_PROGRAM", commission(-1, 40, 45));
    EXPECT_EQ("INVALID_INPUT", commission(-2, 40, 45));
    EXPECT_EQ("334.0", commission(1, 40, 45));
    EXPECT_EQ("140.5", commission(1, 40, 1));
    EXPECT_EQ("10.0", commission(1, 1, 1));

		//T, F, T, F, T, F
    EXPECT_EQ("INVALID_INPUT", commission(0, 0, 0));
    //T, F, T, F, F, T
    EXPECT_EQ("INVALID_INPUT", commission(0, 0, 91));
    //T, F, T, F, F, F 
    EXPECT_EQ("INVALID_INPUT", commission(0, 0, 45));

    //T, F, F, T, T, F
    EXPECT_EQ("INVALID_INPUT", commission(0, 81, 0));
    //T, F, F, T, F, T
    EXPECT_EQ("INVALID_INPUT", commission(0, 81, 91));
    //T, F, F, T, F, F 
    EXPECT_EQ("INVALID_INPUT", commission(0, 81, 45));

    //T, F, F, F, T, F
    EXPECT_EQ("INVALID_INPUT", commission(0, 40, 0));
    //T, F, F, F, F, T
    EXPECT_EQ("INVALID_INPUT", commission(0, 40, 91));
    //T, F, F, F, F, F 
    EXPECT_EQ("INVALID_INPUT", commission(0, 40, 45));

		//F, T, T, F, T, F
    EXPECT_EQ("INVALID_INPUT", commission(71, 0, 0));
    //F, T, T, F, F, T
    EXPECT_EQ("INVALID_INPUT", commission(71, 0, 91));
    //F, T, T, F, F, F 
    EXPECT_EQ("INVALID_INPUT", commission(71, 0, 45));

    //F, T, F, T, T, F
    EXPECT_EQ("INVALID_INPUT", commission(71, 81, 0));
    //F, T, F, T, F, T
    EXPECT_EQ("INVALID_INPUT", commission(71, 81, 91));
    //F, T, F, T, F, F 
    EXPECT_EQ("INVALID_INPUT", commission(71, 81, 45));

    //F, T, F, F, T, F
    EXPECT_EQ("INVALID_INPUT", commission(71, 40, 0));
    //F, T, F, F, F, T
    EXPECT_EQ("INVALID_INPUT", commission(71, 40, 91));
    //F, T, F, F, F, F 
    EXPECT_EQ("INVALID_INPUT", commission(71, 40, 45));

		//F, F, T, F, T, F
    EXPECT_EQ("INVALID_INPUT", commission(35, 0, 0));
    //F, F, T, F, F, T
    EXPECT_EQ("INVALID_INPUT", commission(35, 0, 91));
    //F, F, T, F, F, F 
    EXPECT_EQ("INVALID_INPUT", commission(35, 0, 45));

    //F, F, F, T, T, F
    EXPECT_EQ("INVALID_INPUT", commission(35, 81, 0));
    //F, F, F, T, F, T
    EXPECT_EQ("INVALID_INPUT", commission(35, 81, 91));
    //F, F, F, T, F, F 
    EXPECT_EQ("INVALID_INPUT", commission(35, 81, 45));

    //F, F, F, F, T, F
    EXPECT_EQ("INVALID_INPUT", commission(35, 40, 0));
    //F, F, F, F, F, T
    EXPECT_EQ("INVALID_INPUT", commission(35, 40, 91));
    //F, F, F, F, F, F 
		EXPECT_EQ("10.0", commission(1, 1, 1));
}

int main(int argc, char **argv)
{
		::testing::InitGoogleTest(&argc, argv);
		if(argc > 1){
				std::string test = argv[1];
				if(test.compare("MCDC") != 0) {
					::testing::GTEST_FLAG(filter) = "*.C" + test;
				}
				else {
					::testing::GTEST_FLAG(filter) = "*." + test;
				}
		}
		return RUN_ALL_TESTS();
}
