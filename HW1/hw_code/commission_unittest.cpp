#include "commission.h"
#include "gtest/gtest.h"

//robust boundary value
TEST(BoundaryValueTest, Robust) {
    //70, 80 ,90 
    EXPECT_EQ("INVALID_INPUT", commission(-2, 40, 45));
    EXPECT_EQ("STOP_PROGRAM", commission(-1, 40, 45));
    EXPECT_EQ("INVALID_INPUT", commission(0, 40, 45));
    EXPECT_EQ("334.0", commission(1, 40, 45));
    EXPECT_EQ("343.0", commission(2, 40, 45));
    EXPECT_EQ("640.0", commission(35, 40, 45));
    EXPECT_EQ("701.0", commission(69, 20, 20));
    EXPECT_EQ("710.0", commission(70, 20, 20));
    EXPECT_EQ("INVALID_INPUT", commission(71, 20, 20));
     
    EXPECT_EQ("INVALID_INPUT", commission(35, 0, 20));
    EXPECT_EQ("281.0", commission(35, 1, 20));
    EXPECT_EQ("287.0", commission(35, 2, 20));
    EXPECT_EQ("749.0", commission(35, 79, 20));
    EXPECT_EQ("755.0", commission(35, 80, 20));
    EXPECT_EQ("INVALID_INPUT", commission(35, 81, 20));
    
    EXPECT_EQ("INVALID_INPUT", commission(35, 40, 0));
    EXPECT_EQ("420.0", commission(35, 40, 1));
    EXPECT_EQ("425.0", commission(35, 40, 2));
    EXPECT_EQ("860.0", commission(35, 40, 89));
    EXPECT_EQ("865.0", commission(35, 40, 90));
    EXPECT_EQ("INVALID_INPUT", commission(20, 40, 91));
}

//equivalence class
TEST(EquivalenceClassTest, WeakRobust) {
    EXPECT_EQ("100.0", commission(10, 10, 10));
    EXPECT_EQ("STOP_PROGRAM", commission(-1, 40, 45));
    EXPECT_EQ("INVALID_INPUT", commission(-2, 40, 45));
    EXPECT_EQ("INVALID_INPUT", commission(71, 40, 45));
    EXPECT_EQ("INVALID_INPUT", commission(35, -1, 45));
    EXPECT_EQ("INVALID_INPUT", commission(35, 81, 45));
    EXPECT_EQ("INVALID_INPUT", commission(35, 40, -1));
    EXPECT_EQ("INVALID_INPUT", commission(35, 40, 91));
}

//edge values
TEST(EdgeValuesTest, WeakRobust) {
    EXPECT_EQ("1420.0", commission(70, 80, 90));
    EXPECT_EQ("STOP_PROGRAM", commission(-1, 80, 90));
    EXPECT_EQ("10.0", commission(1, 1, 1));
}

//decision table
