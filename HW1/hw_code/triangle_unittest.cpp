#include "triangle.h"
#include "gtest/gtest.h"

//robust boundary value
TEST(BoundaryValueTest, Robust) {
    EXPECT_EQ("OUT_OF_RANGE", triangle(0, 100, 100));
    EXPECT_EQ("ISOSCELES", triangle(1, 100, 100));
    EXPECT_EQ("ISOSCELES", triangle(2, 100, 100));
    EXPECT_EQ("EQUILATERAL", triangle(100, 100, 100));
    EXPECT_EQ("ISOSCELES", triangle(199, 100, 100));
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(200, 100, 100));
    EXPECT_EQ("OUT_OF_RANGE", triangle(201, 100, 100));

    EXPECT_EQ("OUT_OF_RANGE", triangle(100, 0, 100));
    EXPECT_EQ("ISOSCELES", triangle(100, 1, 100));
    EXPECT_EQ("ISOSCELES", triangle(100, 2, 100));
    EXPECT_EQ("ISOSCELES", triangle(100, 199, 100));
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(100, 200, 100));
    EXPECT_EQ("OUT_OF_RANGE" ,triangle(100, 201, 100));

    EXPECT_EQ("OUT_OF_RANGE", triangle(100, 100, 0));
    EXPECT_EQ("ISOSCELES", triangle(100, 100, 1));
    EXPECT_EQ("ISOSCELES", triangle(100, 100, 2));
    EXPECT_EQ("ISOSCELES", triangle(100, 100, 199));
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(100, 100, 200));
    EXPECT_EQ("OUT_OF_RANGE", triangle(100, 100, 201));
}

//equivalence class
TEST(EquivalenceClassTest, WeakRobust) {
    EXPECT_EQ("ISOSCELES", triangle(1, 100, 100));
    EXPECT_EQ("EQUILATERAL", triangle(100, 100, 100));
    EXPECT_EQ("SCALENE", triangle(100, 101, 102));
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(200, 100, 100));

    EXPECT_EQ("OUT_OF_RANGE", triangle(-1, 100, 100));
    EXPECT_EQ("OUT_OF_RANGE", triangle(100, -1, 100));
    EXPECT_EQ("OUT_OF_RANGE", triangle(100, 100, -1));
    EXPECT_EQ("OUT_OF_RANGE", triangle(201, 100, 100));
    EXPECT_EQ("OUT_OF_RANGE", triangle(100, 201, 100));
    EXPECT_EQ("OUT_OF_RANGE", triangle(100, 100, 201));
}

//edge values
TEST(EdgeValueTest, WeakRobust) {
    //equilateral
    EXPECT_EQ("EQUILATERAL", triangle(1, 1, 1));
    EXPECT_EQ("EQUILATERAL", triangle(200, 200, 200));
    //isosceles
    EXPECT_EQ("ISOSCELES", triangle(1, 2, 2));
    EXPECT_EQ("ISOSCELES", triangle(1, 200, 200));
    EXPECT_EQ("ISOSCELES", triangle(200, 1, 200));
    EXPECT_EQ("ISOSCELES", triangle(200, 200, 1));
    EXPECT_EQ("ISOSCELES", triangle(199, 200, 200));
    //
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(1, 1, 3));
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(1, 1, 200));
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(1, 200, 1));
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(1, 200, 199));
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(200, 1, 1));
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(199, 1, 200));
    //scalene
    EXPECT_EQ("SCALENE", triangle(2, 3, 4));
    EXPECT_EQ("SCALENE", triangle(2, 200, 199));
    EXPECT_EQ("SCALENE", triangle(200, 2, 199));
    EXPECT_EQ("SCALENE", triangle(200, 199, 2));
    EXPECT_EQ("SCALENE", triangle(198, 199, 200));
}

//decision table
TEST(DecisionTableTest, WeakRobust) {
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(4, 1, 2));
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(1, 4, 2));
    EXPECT_EQ("NOT_A_TRIANGLE", triangle(1, 2, 4));

    EXPECT_EQ("ISOSCELES", triangle(100, 100, 50));
    EXPECT_EQ("ISOSCELES", triangle(100, 50, 100));
    EXPECT_EQ("ISOSCELES", triangle(50, 100, 100));

    EXPECT_EQ("EQUILATERAL", triangle(100, 100, 100));
    
    EXPECT_EQ("SCALENE", triangle(2, 3, 4));
}
