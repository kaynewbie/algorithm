//
//  plus-one.c
//  algorithm
//
//  Created by Kai on 2019/7/27.
//  Copyright © 2019 kai. All rights reserved.
//

#include "plus-one.h"
#include "stdlib.h"
#include "stdbool.h"

/*
 https://leetcode.com/problems/plus-one/
 */

bool p_needExpand(int* digits, int digitsSize);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    // 是否需要扩展数组长度
    int needExpand = p_needExpand(digits, digitsSize);
    *returnSize = digitsSize + (0x1 & needExpand);
    
    int diff = 1;
    int *result = malloc(sizeof(int) * (*returnSize));
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] + diff >= 10) {
            result[i + needExpand] = 0;
            diff = 1;
        } else {
            result[i + needExpand] = digits[i] + diff;
            diff = 0;
        }
    }
    if (needExpand) {
        result[0] = 1;
    }
    return result;
}

// 是否需要扩展数组长度
bool p_needExpand(int* digits, int digitsSize) {
    for (int i = 0; i < digitsSize; i++) {
        if (digits[i] != 9) {
            return false;
        }
    }
    return true;
}

// MARK:- 测试
static void printArray(int *nums, int numsSize) {
    printf("nums: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/*
 input = {1, 2, 3}
 output = {1, 2, 4}
 */
void testPlusOne1() {
    const int length = 3;
    int digits[length] = {1, 2, 3};
    int returnSize = 0;
    int *output = plusOne(digits, length, &returnSize);
    printf("Inputs: ");
    printArray(digits, length);
    printf("Outputs: ");
    printArray(output, returnSize);
    printf("\n");
}

/*
 input = {1, 2, 9}
 output = {1, 3, 0}
 */
void testPlusOne2() {
    const int length = 3;
    int digits[length] = {1, 2, 9};
    int returnSize = 0;
    int *output = plusOne(digits, length, &returnSize);
    printf("Inputs: ");
    printArray(digits, length);
    printf("Outputs: ");
    printArray(output, returnSize);
    printf("\n");
}

/*
 input = {1, 9, 9}
 output = {2, 0, 0}
 */
void testPlusOne3() {
    const int length = 3;
    int digits[length] = {1, 9, 9};
    int returnSize = 0;
    int *output = plusOne(digits, length, &returnSize);
    printf("Inputs: ");
    printArray(digits, length);
    printf("Outputs: ");
    printArray(output, returnSize);
    printf("\n");
}

/*
 input = {0}
 output = {1}
 */
void testPlusOne4() {
    const int length = 1;
    int digits[length] = {0};
    int returnSize = 0;
    int *output = plusOne(digits, length, &returnSize);
    printf("Inputs: ");
    printArray(digits, length);
    printf("Outputs: ");
    printArray(output, returnSize);
    printf("\n");
}

/*
 input = {9}
 output = {1, 0}
 */
void testPlusOne5() {
    const int length = 1;
    int digits[length] = {9};
    int returnSize = 0;
    int *output = plusOne(digits, length, &returnSize);
    printf("Inputs: ");
    printArray(digits, length);
    printf("Outputs: ");
    printArray(output, returnSize);
    printf("\n");
}

/*
 input = {1, 4, 5, 2, 5, 1, 9, 9}
 output = {1, 4, 5, 2, 5, 2, 0, 0}
 */
void testPlusOne6() {
    const int length = 8;
    int digits[length] = {1, 4, 5, 2, 5, 1, 9, 9};
    int returnSize = 0;
    int *output = plusOne(digits, length, &returnSize);
    printf("Inputs: ");
    printArray(digits, length);
    printf("Outputs: ");
    printArray(output, returnSize);
    printf("\n");
}

/*
 input = {9,8,7,6,5,4,3,2,1,0}
 output = {9,8,7, 6, 5, 4, 3, 2, 1, 1}
 */
void testPlusOne7() {
    const int length = 10;
    int digits[length] = {9,8,7,6,5,4,3,2,1,0};
    int returnSize = 0;
    int *output = plusOne(digits, length, &returnSize);
    printf("Inputs: ");
    printArray(digits, length);
    printf("Outputs: ");
    printArray(output, returnSize);
    printf("\n");
}

/*
 input = {9,9,9,0,1}
 */
void testPlusOne8() {
    const int length = 5;
    int digits[length] = {9,9,9,0,1};
    int returnSize = 0;
    int *output = plusOne(digits, length, &returnSize);
    printf("Inputs: ");
    printArray(digits, length);
    printf("Outputs: ");
    printArray(output, returnSize);
    printf("\n");
}

/*
 input = {9,9,9,0,9}
 */
void testPlusOne9() {
    const int length = 5;
    int digits[length] = {9,9,9,0,9};
    int returnSize = 0;
    int *output = plusOne(digits, length, &returnSize);
    printf("Inputs: ");
    printArray(digits, length);
    printf("Outputs: ");
    printArray(output, returnSize);
    printf("\n");
}

void testPlusOne(void) {
    testPlusOne1();
    testPlusOne2();
    testPlusOne3();
    testPlusOne4();
    testPlusOne5();
    testPlusOne6();
    testPlusOne7();
    testPlusOne8();
    testPlusOne9();
}
