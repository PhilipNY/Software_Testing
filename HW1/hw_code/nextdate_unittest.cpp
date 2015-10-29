#include "nextdate.h"
#include "gtest/gtest.h"

//robust boundary value
TEST(BoundaryValueTest, Robust) {
    //year
    EXPECT_EQ("INVALID_INPUT", nextdate(1811, 7, 15));
    EXPECT_EQ("1812/7/16", nextdate(1812, 7, 15));
    EXPECT_EQ("1813/7/16", nextdate(1813, 7, 15));    
    EXPECT_EQ("1912/7/16", nextdate(1912, 7, 15));
    EXPECT_EQ("2011/7/16", nextdate(2011, 7, 15));
    EXPECT_EQ("2012/7/16", nextdate(2012, 7, 15));
    EXPECT_EQ("INVALID_INPUT", nextdate(2013, 7, 15));

    //month
    EXPECT_EQ("INVALID_INPUT", nextdate(1912, 0, 15));
    EXPECT_EQ("1912/2/16", nextdate(1912, 2, 15));
    EXPECT_EQ("1912/1/16", nextdate(1912, 1, 15));
    EXPECT_EQ("1912/11/16", nextdate(1912, 11, 15));
    EXPECT_EQ("1912/12/16", nextdate(1912, 12, 15));
    EXPECT_EQ("INVALID_INPUT", nextdate(1912, 13, 15));

    //day
    EXPECT_EQ("INVALID_INPUT", nextdate(1912, 7, 32));
    EXPECT_EQ("1912/8/1", nextdate(1912, 7, 31));
    EXPECT_EQ("1912/7/31", nextdate(1912, 7, 30));
    EXPECT_EQ("1912/7/3", nextdate(1912, 7, 2));
    EXPECT_EQ("1912/7/2", nextdate(1912, 7, 1));
    EXPECT_EQ("INVALID_INPUT", nextdate(1912, 7, 0));
}

TEST(EquivalenceClassTest, WeakRobust) {
    //year: leap, common
    //month: 30, 31, Feb.
    //day:  >=1 && < 28, 28, 29, 30, 31 
    
    /*WeakNormal*/
    EXPECT_EQ("1912/6/15", nextdate(1912, 6, 14));
    EXPECT_EQ("1912/6/29", nextdate(1912, 6, 28));
    EXPECT_EQ("1912/6/30", nextdate(1912, 6, 29));
    EXPECT_EQ("1912/7/1", nextdate(1912, 6, 30));
    EXPECT_EQ("1912/8/1", nextdate(1912, 7, 31));
    
    /*robust*/
    EXPECT_EQ("INVALID_INPUT", nextdate(1811, 6, 15));
    EXPECT_EQ("INVALID_INPUT", nextdate(2013, 6, 15));
    EXPECT_EQ("INVALID_INPUT", nextdate(1912, -1, 15));
    EXPECT_EQ("INVALID_INPUT", nextdate(1912, 13, 15));
    EXPECT_EQ("INVALID_INPUT", nextdate(1912, 6, -1));
    EXPECT_EQ("INVALID_INPUT", nextdate(1912, 6, 32));
}


//edge values
TEST(EdgeValueTest, WeakRobust) {
    //leap year + 30 days month + 30 day
    EXPECT_EQ("1812/5/1", nextdate(1812, 4, 30));
    EXPECT_EQ("2012/5/1", nextdate(2012, 4, 30));
    EXPECT_EQ("1812/12/1", nextdate(1812, 11, 30));
    EXPECT_EQ("2012/12/1", nextdate(2012, 11, 30));

    //leap year + 31 days month + 31 day
    EXPECT_EQ("1812/2/1", nextdate(1812, 1, 31));
    EXPECT_EQ("2012/2/1", nextdate(2012, 1, 31));
    EXPECT_EQ("1813/1/1", nextdate(1812, 12, 31));
    EXPECT_EQ("OVER_MAX_YEAR", nextdate(2012, 12, 31));

    //leap year + Feb. + 29 day
    EXPECT_EQ("1812/3/1", nextdate(1812, 2, 29));
    EXPECT_EQ("2012/3/1", nextdate(2012, 2, 29));
    
    //common year + Feb. + 28 day
    EXPECT_EQ("1813/3/1", nextdate(1813, 2, 28));
    EXPECT_EQ("2011/3/1", nextdate(2011, 2, 28));

    //others are redundant
}

//decision table based
TEST(DecisionTableTest, WeakRobust) {
    //year: y1 = leap year, y2 = common year
    //month:  m1 = 30days, m2 = 31days but not Dec, m3 = Dec., m4 = Feb.
    //day: d1 = (>=1 && <= 28), d2 = 28 ,d3 = 29, d4 = 30, d5 = 31

    //m1 + (d1 or d2 or d3)
    EXPECT_EQ("1812/4/2", nextdate(1812, 4, 1));

    //m1 + d4
    EXPECT_EQ("1812/5/1", nextdate(1812, 4, 30));

    //(m2 or m3) + (d1 or d2 or d3 or d4)
    EXPECT_EQ("1812/5/2", nextdate(1812, 5, 1));

    //m2 + d5
    EXPECT_EQ("1812/6/1", nextdate(1812, 5, 31));

    //m3 + d5
    EXPECT_EQ("1813/1/1", nextdate(1812, 12, 31));

    //m4 + d1
    EXPECT_EQ("1812/2/28", nextdate(1812, 2, 27));

    //y1 + m4 + d2
    EXPECT_EQ("1812/2/29", nextdate(1812, 2, 28));

    //y2 + m4 + d2
    EXPECT_EQ("1813/3/1", nextdate(1813, 2, 28));

    //y1 + m4 + d3
    EXPECT_EQ("1812/3/1", nextdate(1812, 2, 29));
}
