//
//  climbing-stairs.c
//  algorithm
//
//  Created by Kai on 2019/7/29.
//  Copyright © 2019 kai. All rights reserved.
//

#include "climbing-stairs.h"

/*
 https://leetcode.com/problems/climbing-stairs/
 */

/*
 n=1, r=1
 n=2, r=2
 n=3, r=3
 
 */
int climbStairs(int n){
    int result = 0;
    int p = 1, q = 0;
    
    for (int i = 1; i <= n; i++) {
        result = p + q;
        q = p;
        p = result;
    }
    return result;
}

void testClimbStairs1(void) {
    int n = 0;
    int result = climbStairs(n);
    printf("%d stairs, result: %d\n", n, result);
}

void testClimbStairs2(void) {
    int n = 10;
    int result = climbStairs(n);
    printf("%d stairs, result: %d\n", n, result);
}

void testClimbStairs3(void) {
    int n = 20;
    int result = climbStairs(n);
    printf("%d stairs, result: %d\n", n, result);
}

void testClimbStairs4(void) {
    int n = 100;
    int result = climbStairs(n);
    printf("%d stairs, result: %d\n", n, result);
}

void testClimbStairs(void) {
    testClimbStairs1();
    testClimbStairs2();
    testClimbStairs3();
    testClimbStairs4();
}
