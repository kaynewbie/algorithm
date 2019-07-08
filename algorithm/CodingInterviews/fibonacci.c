//
//  fibonacci.c
//  algorithm
//
//  Created by Kai on 2019/7/7.
//  Copyright © 2019 kai. All rights reserved.
//

#include "fibonacci.h"

/*
 n=0, f(n)=0
 n=1, f(n)=1
 n>1, f(n)=f(n-1)+f(n-2)
 */

// MARK:- 循环
int fibonacciLoop(int n) {
    int pre = 0;
    int next = 1;
    int result = 0;
    
    if (n == 0) {
        result = pre;
    } else if (n == 1) {
        result = next;
    } else {
        for (int i = 2; i <= n; i++) {
            result = pre + next;
            pre = next;
            next = result;
        }
    }
    return result;
}

void testFibonacciLoop() {
    int n = 10;
    int result = fibonacciLoop(n);
    printf("resultLoop=%d\n", result);
}

// MARK:- 递归
int fibonacciRecursive(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}

/*
 n = 10
    0, 1, 1, 2, 3, 5 ,8, 13, 21, 34, 55...
 */
void testFibonacciRecursive() {
    int n = 10;
    int result = fibonacciRecursive(n);
    
    printf("resultRecursive=%d\n", result);
}
