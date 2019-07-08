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
void fibonacciLoop(int n) {
    int pre = 0;
    int next = 1;
    int result = 0;

    for (int i = 0; i < n; i++) {
        if (i <= 1) {
            result = i;
        } else {
            result = pre + next;
            pre = next;
            next = result;
        }
        printf("%d ", result);
    }
    printf("\n");
}

void testFibonacciLoop() {
    int n;
    printf("please input a number:");
    scanf("%d", &n);
    fibonacciLoop(n);
}

// MARK:- 递归
int fibonacciRecursive(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}

/*
 n = 10
    0, 1, 1, 2, 3, 5 ,8, 13, 21, 34, 55...
 */
void testFibonacciRecursive() {
    int n;
    printf("please input a number:");
    scanf("%d", &n);
    
    for (int i = 0; i <= n; i++) {
        int result = fibonacciRecursive(i);
        printf("%d ", result);
    }
}
