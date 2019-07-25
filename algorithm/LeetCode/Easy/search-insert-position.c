//
//  search-insert-position.c
//  algorithm
//
//  Created by Kai on 2019/7/25.
//  Copyright © 2019 kai. All rights reserved.
//

#include "search-insert-position.h"

/*
 https://leetcode.com/problems/search-insert-position/
 */

typedef int (*SearchInsertFunc)(int *nums, int numsSize, int target);

// MARK:- 方法一、遍历查找
/**
 方法一、时间复杂度O(n)，空间复杂度O(1)
 索引初始为 0
 遍历数组，拿当前元素和目标值比较
 <=：结果就是当前索引值，>：继续遍历
 直到循环结束，返回 numSize
 */
int searchInsert(int* nums, int numsSize, int target) {
    return 0;
}

// MARK:- 方法二、二分查找

int searchInsertBinary(int *nums, int start, int end, int target);

/*
 方法二、时间复杂度O(log(n))，空间复杂度O(1)
 二分查找
 */
int searchInsert2(int *nums, int numsSize, int target) {
    int result = searchInsertBinary(nums, 0, numsSize - 1, target);
    return result;
}

int searchInsertBinary(int *nums, int start, int end, int target) {
    if (start == end) {
        return target <= nums[start] ? start : start + 1;
    }
    int median = (start + end) >> 1;
    if (target == nums[median]) {
        return median;
    } else if (target < nums[median]) {
        return searchInsertBinary(nums, start, median, target);
    } else {
        return searchInsertBinary(nums, median + 1, end, target);
    }
}

// MARK:- 测试
static void printArray(int *nums, int numsSize) {
    printf("nums: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/**
 nums = {1, 2, 3}
 numSize = 3
 target = 2
 result = 1
 */
void testSearchInsert1(SearchInsertFunc func) {
    const int numSize = 3;
    int nums[numSize] = {1, 2, 3};
    int target = 2;
    int result = func(nums, numSize, target);
    printArray(nums, numSize);
    printf("target: %d should be in %d\n", target, result);
}

/**
 nums = {1, 2, 3}
 numSize = 3
 target = 1
 result = 0
 */
void testSearchInsert2(SearchInsertFunc func) {
    const int numSize = 3;
    int nums[numSize] = {1, 2, 3};
    int target = 1;
    int result = func(nums, numSize, target);
    printArray(nums, numSize);
    printf("target: %d should be in %d\n", target, result);
}

/**
 nums = {1, 2, 3}
 numSize = 3
 target = 3
 result = 2
 */
void testSearchInsert3(SearchInsertFunc func) {
    const int numSize = 3;
    int nums[numSize] = {1, 2, 3};
    int target = 3;
    int result = func(nums, numSize, target);
    printArray(nums, numSize);
    printf("target: %d should be in %d\n", target, result);
}

/**
 nums = {1, 2, 3}
 numSize = 3
 target = 4
 result = 3
 */
void testSearchInsert4(SearchInsertFunc func) {
    const int numSize = 3;
    int nums[numSize] = {1, 2, 3};
    int target = 4;
    int result = func(nums, numSize, target);
    printArray(nums, numSize);
    printf("target: %d should be in %d\n", target, result);
}

/**
 nums = {1, 2, 3, 3, 10}
 numSize = 5
 target = 0
 result = 0
 */
void testSearchInsert5(SearchInsertFunc func) {
    const int numSize = 3;
    int nums[numSize] = {1, 2, 3};
    int target = 0;
    int result = func(nums, numSize, target);
    printArray(nums, numSize);
    printf("target: %d should be in %d\n", target, result);
}

/**
 nums = {1, 2, 3, 3, 10}
 numSize = 5
 target = 7
 result = 4
 */
void testSearchInsert6(SearchInsertFunc func) {
    const int numSize = 5;
    int nums[numSize] = {1, 2, 3, 3, 10};
    int target = 7;
    int result = func(nums, numSize, target);
    printArray(nums, numSize);
    printf("target: %d should be in %d\n", target, result);
}

/**
 nums = {1}
 numSize = 1
 target = 2
 result = 1
 */
void testSearchInsert7(SearchInsertFunc func) {
    const int numSize = 1;
    int nums[numSize] = {1};
    int target = 2;
    int result = func(nums, numSize, target);
    printArray(nums, numSize);
    printf("target: %d should be in %d\n", target, result);
}

void testSearchInsert(void) {
    testSearchInsert1(searchInsert2);
    testSearchInsert2(searchInsert2);
    testSearchInsert3(searchInsert2);
    testSearchInsert4(searchInsert2);
    testSearchInsert5(searchInsert2);
    testSearchInsert6(searchInsert2);
    testSearchInsert7(searchInsert2);
}
