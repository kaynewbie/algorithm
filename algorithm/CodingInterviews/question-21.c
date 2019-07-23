//
//  question-21.c
//  algorithm
//
//  Created by Kai on 2019/7/21.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-21.h"
#include "stdbool.h"

/*
 对给定数组重新排序：
    * 按照奇偶排序，奇数在数组前半部分，偶数在数组后半部分
    * 按照正负排序，负数在前，正数在后
    * 能否被3整除排序
    ...
 */

static bool isEven(int);
static void swap(int *, int *);
static void printArray(int *, int);

/**
 @param array 数组
 @param length 数组长度
 @param func 回调函数，排序的决策
 */
void reorderArray(int *array, int length, bool (*func)(int)) {
    if (length <= 0) {
        return;
    }
    int preIdx = 0;
    int postIdx = length - 1;
    
    while (preIdx < postIdx) {
        while (func(array[preIdx]) == false) {
            preIdx++;
        }
        while (func(array[postIdx]) == true) {
            postIdx--;
        }
        if (preIdx < postIdx) {
            swap(&array[preIdx], &array[postIdx]);
            preIdx++;
            postIdx--;
        } else {
            return;
        }
    }
}

static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static bool isEven(int n) {
    return (n & 0x1) == 0;
}

//static bool isPositive(int n) {
//    return n > 0;
//}

static void printArray(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/**
 array = {1, 4, 2, 5, 46, 7, 45}
 result = [1, 45, 7, 5, 2, 4]
 */
void testReorderArrayByEven1() {
    const int length = 7;
    int array[length] = {1, 4, 2, 5, 46, 7, 45};
    printf("array before reorder: ");
    printArray(array, length);
    reorderArray(array, length, isEven);
    printf("array after reorder: ");
    printArray(array, length);
}

/**
 array = {1, 2, 3, 4, 5, 6, 7}
 result = [1, 7, 3, 5, 6, 2]
 */
void testReorderArrayByEven2() {
    const int length = 7;
    int array[length] = {1, 2, 3, 4, 5, 6, 7};
    printf("array before reorder: ");
    printArray(array, length);
    reorderArray(array, length, isEven);
    printf("array after reorder: ");
    printArray(array, length);
}

/**
 array = {1, 3, 5, 2, 4, 6}
 result = {1, 3, 5, 2, 4, 6}
 */
void testReorderArrayByEven3() {
    const int length = 6;
    int array[length] = {1, 3, 5, 2, 4, 6};
    printf("array before reorder: ");
    printArray(array, length);
    reorderArray(array, length, isEven);
    printf("array after reorder: ");
    printArray(array, length);
    printf("\n");
}

void testReorderArray(void) {
    testReorderArrayByEven1();
    testReorderArrayByEven2();
    testReorderArrayByEven3();
}
