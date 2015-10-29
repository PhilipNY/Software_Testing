#include "triangle.h"

string triangle(int a, int b, int c) {
    if(a > 200 || a < 1 || b > 200 || b < 1 || c > 200 || c < 1) {
        return "OUT_OF_RANGE";
    }
    else if(a == b && b == c) {
        return "EQUILATERAL";
    }
    else if((a + b > c) && (a + c > b) && (b + c > a)) {
        if(a == b || b == c || a == c) {
            return "ISOSCELES";
        }
        else {
            return "SCALENE";
        }
    }
    else {
        return "NOT_A_TRIANGLE";
    }
}
