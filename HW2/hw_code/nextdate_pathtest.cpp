#include "nextdate.h"
#include "string"
#include "gtest/gtest.h"

TEST(nextdate, C0) {
    EXPECT_EQ("INVALID_INPUT", nextdate(1811, 7, 15));
    EXPECT_EQ("OVER_MAX_YEAR", nextdate(2012, 12, 31));

    EXPECT_EQ("INVALID_INPUT", nextdate(2012, 2, 30));
    EXPECT_EQ("INVALID_INPUT", nextdate(2011, 2, 30));
    EXPECT_EQ("2012/3/1", nextdate(2012, 2, 29));
    EXPECT_EQ("2012/2/29", nextdate(2012, 2, 28));

    EXPECT_EQ("INVALID_INPUT", nextdate(1912, 4, 31));
    EXPECT_EQ("1912/5/1", nextdate(1912, 4, 30));
    EXPECT_EQ("1912/4/30", nextdate(1912, 4, 29));

    EXPECT_EQ("1913/1/1", nextdate(1912, 12, 31));
    EXPECT_EQ("1912/11/1", nextdate(1912, 10, 31));
    EXPECT_EQ("1912/10/31", nextdate(1912, 10, 30));
}

TEST(nextdate, C1) {
    EXPECT_EQ("INVALID_INPUT", nextdate(1811, 7, 15));
    EXPECT_EQ("OVER_MAX_YEAR", nextdate(2012, 12, 31));

    EXPECT_EQ("INVALID_INPUT", nextdate(2012, 2, 30));
    EXPECT_EQ("INVALID_INPUT", nextdate(2011, 2, 30));
    EXPECT_EQ("2012/3/1", nextdate(2012, 2, 29));
    EXPECT_EQ("2012/2/29", nextdate(2012, 2, 28));

    EXPECT_EQ("INVALID_INPUT", nextdate(1912, 4, 31));
    EXPECT_EQ("1912/5/1", nextdate(1912, 4, 30));
    EXPECT_EQ("1912/4/30", nextdate(1912, 4, 29));

    EXPECT_EQ("1913/1/1", nextdate(1912, 12, 31));
    EXPECT_EQ("1912/11/1", nextdate(1912, 10, 31));
    EXPECT_EQ("1912/10/31", nextdate(1912, 10, 30));
}

TEST(nextdate, C2) {
    EXPECT_EQ("INVALID_INPUT", nextdate(1811, 7, 15));
    EXPECT_EQ("OVER_MAX_YEAR", nextdate(2012, 12, 31));

    EXPECT_EQ("INVALID_INPUT", nextdate(2012, 2, 30));
    EXPECT_EQ("INVALID_INPUT", nextdate(2011, 2, 30));
    EXPECT_EQ("2012/3/1", nextdate(2012, 2, 29));
    EXPECT_EQ("2012/2/29", nextdate(2012, 2, 28));

    EXPECT_EQ("INVALID_INPUT", nextdate(1912, 4, 31));
    EXPECT_EQ("1912/5/1", nextdate(1912, 4, 30));
    EXPECT_EQ("1912/4/30", nextdate(1912, 4, 29));

    EXPECT_EQ("1913/1/1", nextdate(1912, 12, 31));
    EXPECT_EQ("1912/11/1", nextdate(1912, 10, 31));
    EXPECT_EQ("1912/10/31", nextdate(1912, 10, 30));
}

TEST(nextdate, MCDC) {
		EXPECT_EQ("INVALID_INPUT", nextdate(1811, 7, 15));
    EXPECT_EQ("OVER_MAX_YEAR", nextdate(2012, 12, 31));

    EXPECT_EQ("INVALID_INPUT", nextdate(2012, 2, 30));
    EXPECT_EQ("INVALID_INPUT", nextdate(2011, 2, 30));
    EXPECT_EQ("2012/3/1", nextdate(2012, 2, 29));
    EXPECT_EQ("2012/2/29", nextdate(2012, 2, 28));

    EXPECT_EQ("INVALID_INPUT", nextdate(1912, 4, 31));
    EXPECT_EQ("1912/5/1", nextdate(1912, 4, 30));
    EXPECT_EQ("1912/4/30", nextdate(1912, 4, 29));

    EXPECT_EQ("1913/1/1", nextdate(1912, 12, 31));
    EXPECT_EQ("1912/11/1", nextdate(1912, 10, 31));
    EXPECT_EQ("1912/10/31", nextdate(1912, 10, 30));

		/*first if*/
		//T, F, T, F, T, F
    EXPECT_EQ("INVALID_INPUT", nextdate(1811, 0, 0));
    //T, F, T, F, F, T
    EXPECT_EQ("INVALID_INPUT", nextdate(1811, 0, 32));
    //T, F, T, F, F, F 
    EXPECT_EQ("INVALID_INPUT", nextdate(1811, 0, 31));

    //T, F, F, T, T, F
    EXPECT_EQ("INVALID_INPUT", nextdate(1811, 13, 0));
    //T, F, F, T, F, T
    EXPECT_EQ("INVALID_INPUT", nextdate(1811, 13, 32));
    //T, F, F, T, F, F 
    EXPECT_EQ("INVALID_INPUT", nextdate(1811, 13, 31));

    //T, F, F, F, T, F
    EXPECT_EQ("INVALID_INPUT", nextdate(1811, 12, 0));
    //T, F, F, F, F, T
    EXPECT_EQ("INVALID_INPUT", nextdate(1811, 12, 32));
    //T, F, F, F, F, F 
    EXPECT_EQ("INVALID_INPUT", nextdate(1811, 12, 31));

		//F, T, T, F, T, F
    EXPECT_EQ("INVALID_INPUT", nextdate(2013, 0, 0));
    //F, T, T, F, F, T
    EXPECT_EQ("INVALID_INPUT", nextdate(2013, 0, 32));
    //F, T, T, F, F, F 
    EXPECT_EQ("INVALID_INPUT", nextdate(2013, 0, 31));

    //F, T, F, T, T, F
    EXPECT_EQ("INVALID_INPUT", nextdate(2013, 13, 0));
    //F, T, F, T, F, T
    EXPECT_EQ("INVALID_INPUT", nextdate(2013, 13, 32));
    //F, T, F, T, F, F 
    EXPECT_EQ("INVALID_INPUT", nextdate(2013, 13, 31));

    //F, T, F, F, T, F
    EXPECT_EQ("INVALID_INPUT", nextdate(2013, 12, 0));
    //F, T, F, F, F, T
    EXPECT_EQ("INVALID_INPUT", nextdate(2013, 12, 32));
    //F, T, F, F, F, F 
    EXPECT_EQ("INVALID_INPUT", nextdate(2013, 12, 31));

		//F, F, T, F, T, F
    EXPECT_EQ("INVALID_INPUT", nextdate(2013, 0, 0));
    //F, F, T, F, F, T
    EXPECT_EQ("INVALID_INPUT", nextdate(2013, 0, 32));
    //F, F, T, F, F, F 
    EXPECT_EQ("INVALID_INPUT", nextdate(2013, 0, 31));

    //F, F, F, T, T, F
    EXPECT_EQ("INVALID_INPUT", nextdate(2012, 13, 0));
    //F, F, F, T, F, T
    EXPECT_EQ("INVALID_INPUT", nextdate(2012, 13, 32));
    //F, F, F, T, F, F 
    EXPECT_EQ("INVALID_INPUT", nextdate(2012, 13, 31));

    //F, F, F, F, T, F
    EXPECT_EQ("INVALID_INPUT", nextdate(2012, 12, 0));
    //F, F, F, F, F, T
    EXPECT_EQ("INVALID_INPUT", nextdate(2012, 12, 32));
    //F, F, F, F, F, F 
    EXPECT_EQ("2012/1/1", nextdate(2011, 12, 31));

		/*second if*/
		//T, T, T
    EXPECT_EQ("OVER_MAX_YEAR", nextdate(2012, 12, 31));
		//T, T, F
    EXPECT_EQ("2012/12/31", nextdate(2012, 12, 30));
		//T, F, T
    EXPECT_EQ("2012/11/1", nextdate(2012, 10, 31));
		//T, F, F
    EXPECT_EQ("2012/12/1", nextdate(2012, 11, 30));
		//F, T, T
    EXPECT_EQ("2012/1/1", nextdate(2011, 12, 31));
		//F, T, F
    EXPECT_EQ("2011/12/31", nextdate(2011, 12, 30));
		//F, F, T
    EXPECT_EQ("2011/11/1", nextdate(2011, 10, 31));
		//F, F, F
    EXPECT_EQ("2011/12/1", nextdate(2011, 11, 30));

		/*third if*/
		//T, T
    EXPECT_EQ("INVALID_INPUT", nextdate(2012, 2, 30));
		//T, F
    EXPECT_EQ("2012/3/1", nextdate(2012, 2, 29));
		//F, T
    EXPECT_EQ("INVALID_INPUT", nextdate(2011, 2, 30));
		//F, F
    EXPECT_EQ("2011/2/2", nextdate(2011, 2, 1));

		/*fourth if*/
		//T, T
    EXPECT_EQ("INVALID_INPUT", nextdate(2011, 2, 30));
		//T, F
    EXPECT_EQ("2011/3/1", nextdate(2011, 2, 28));
		//F, T
    EXPECT_EQ("INVALID_INPUT", nextdate(2012, 2, 30));
		//F, F
    EXPECT_EQ("2012/2/2", nextdate(2012, 2, 1));
		
		/*fifth if*/
		//T, F
		//T, T, F, F
    EXPECT_EQ("2012/3/1", nextdate(2012, 2, 29));
		//F, T
		//F, F, T, T
    EXPECT_EQ("2011/3/1", nextdate(2011, 2, 28));
		//F, F
		//T, F, F, T
    EXPECT_EQ("2012/2/29", nextdate(2012, 2, 28));
		//T, F, F, F
    EXPECT_EQ("2012/2/2", nextdate(2012, 2, 1));
		//F, T, T, F
    EXPECT_EQ("INVALID_INPUT", nextdate(2011, 2, 29));
		//F, F, T, F
    EXPECT_EQ("2011/2/2", nextdate(2011, 2, 1));
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
