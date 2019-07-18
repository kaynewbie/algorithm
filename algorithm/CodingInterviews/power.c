//
//  power.c
//  algorithm
//
//  Created by Kai on 2019/7/19.
//  Copyright © 2019 kai. All rights reserved.
//

#include "power.h"
#include "math.h"

/**
 未处理指数为负数和结果越界的情况
 */
double power(double base, int exponent) {
    if (exponent < 0) {
        
    }
    return 0;
}

double powerCore(double base, int exponent) {
    if (exponent == 0) {
        return 0;
    } else if (exponent == 1) {
        return base;
    }
    double result = power(base, exponent >> 1);
    result *= result;
    if ((exponent & 0x1) == 1) {
        result *= base;
    }
    return result;
}


/**
 base = 2, exponent = 1
 */
void testPower1(void) {
    double base = 2;
    int exponent = 1;
    double result = power(base, exponent);
    printf("%lf ^ %d = %lf\n", base, exponent, result);
}

/**
 base = 2, exponent = 5
 */
void testPower2(void) {
    double base = 2;
    int exponent = 5;
    double result = power(base, exponent);
    printf("%lf ^ %d = %lf\n", base, exponent, result);
}

/**
 base = 2, exponent = 10
 */
void testPower3(void) {
    double base = 2;
    int exponent = 10;
    double result = power(base, exponent);
    printf("%lf ^ %d = %lf\n", base, exponent, result);
}

/**
 base = 10, exponent = 10
 */
void testPower4(void) {
    double base = 10;
    int exponent = 10;
    double result = power(base, exponent);
    printf("%lf ^ %d = %lf\n", base, exponent, result);
}

/**
 base = 0, exponent = 0
 */
void testPower5(void) {
    double base = 0;
    int exponent = 0;
    double result = power(base, exponent);
    printf("%lf ^ %d = %lf\n", base, exponent, result);
}

/**
 base = 2, exponent = -10
 */
void testPower6(void) {
    double base = 2;
    int exponent = -10;
    double result = power(base, exponent);
    printf("%lf ^ %d = %lf\n", base, exponent, result);
}

/**
 base = -2, exponent = 10
 */
void testPower7(void) {
    double base = -2;
    int exponent = 9;
    double result = power(base, exponent);
    printf("%lf ^ %d = %lf\n", base, exponent, result);
}

void testPower(void) {
    testPower1();
    testPower2();
    testPower3();
    testPower4();
    testPower5();
//    testPower6();
    testPower7();
}
