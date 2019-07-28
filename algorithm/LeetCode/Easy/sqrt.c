//
//  sqrt.c
//  algorithm
//
//  Created by Kai on 2019/7/28.
//  Copyright © 2019 kai. All rights reserved.
//

#include "sqrt.h"

/*
 https://leetcode.com/problems/sqrtx/
 */

typedef int (*SqrtFunc)(int x);

// MARK:- method 1
// median * median 可能会造成整型溢出
int mySqrt(int x){
    
    int median = x >> 1;
    int start = 0;
    int end = x;
    int tmp;
    while (start <= end) {
        median = (start + end) >> 1;
        tmp = median * median;
        if (tmp == x) {
            return median;
        } else if (tmp < x) {
            if (((median + 1) * (median + 1)) > x ) {
                return median;
            } else {
                start = median + 1;
            }
        } else {
            end = median;
        }
    }
    
    return 0;
}

// MARK:- newton's method
// 链接：https://zh.wikipedia.org/wiki/%E7%89%9B%E9%A1%BF%E6%B3%95
int mySqrt1(int x){
    int n1, n2 = x/2;
    
    if (x == 1){n1 = 1;}
    else if(x == 0){n1 = 0;}
    else{
        do {
            n1 = n2;
            
            n2 = (n1 + x/n1)/2;
        } while(n1 > n2);
    }
    
    return n1;
}

// MARK:- test
/*
 x = 4
 */
void testMySqrt1(SqrtFunc func) {
    int x = 4;
    int result = func(x);
    printf("square root of %d is %d\n", x, result);
}

/*
 x = 8
 */
void testMySqrt2(SqrtFunc func) {
    int x = 8;
    int result = func(x);
    printf("square root of %d is %d\n", x, result);
}

/*
 x = 16
 */
void testMySqrt3(SqrtFunc func) {
    int x = 16;
    int result = func(x);
    printf("square root of %d is %d\n", x, result);
}

/*
 x = 0
 */
void testMySqrt4(SqrtFunc func) {
    int x = 0;
    int result = func(x);
    printf("square root of %d is %d\n", x, result);
}

/*
 x = 25
 */
void testMySqrt5(SqrtFunc func) {
    int x = 25;
    int result = func(x);
    printf("square root of %d is %d\n", x, result);
}

void testMySqrtMethod2(void) {
    testMySqrt1(mySqrt1);
    testMySqrt2(mySqrt1);
    testMySqrt3(mySqrt1);
    testMySqrt4(mySqrt1);
    testMySqrt5(mySqrt1);
}
