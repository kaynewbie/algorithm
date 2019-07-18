//
//  bit-operation.c
//  algorithm
//
//  Created by Kai on 2019/7/18.
//  Copyright © 2019 kai. All rights reserved.
//

#include "bit-operation.h"
#include "limits.h"

/**
 O(m), m is one count
 */
int countOneInBinaryNum(int n) {
    int count = 0;
    while (n) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

/**
 n=0
 */
void testCountOneInBinaryNum1() {
    int n = 0;
    int result = countOneInBinaryNum(n);
    printf("number of one in %d: %d\n", n, result);
}

/**
 n=INT_MAX
 */
void testCountOneInBinaryNum2() {
    int n = INT_MAX;
    int result = countOneInBinaryNum(n);
    printf("number of one in %d: %d\n", n, result);
}

/**
 n=INT_MIN
 */
void testCountOneInBinaryNum3() {
    int n = INT_MIN;
    int result = countOneInBinaryNum(n);
    printf("number of one in %d: %d\n", n, result);
}

/**
 n=123
 */
void testCountOneInBinaryNum4() {
    int n = 123;
    int result = countOneInBinaryNum(n);
    printf("number of one in %d: %d\n", n, result);
}

void testCountOneInBinaryNum(void) {
    testCountOneInBinaryNum1();
    testCountOneInBinaryNum2();
    testCountOneInBinaryNum3();
    testCountOneInBinaryNum4();
}
