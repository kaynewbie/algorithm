//
//  maximum-subarray.c
//  algorithm
//
//  Created by Kai on 2019/7/27.
//  Copyright © 2019 kai. All rights reserved.
//

#include "maximum-subarray.h"
#include "limits.h"
#include "math.h"

/*
 https://leetcode.com/problems/maximum-subarray/
 */

#define MAX(x, y) ((x > y) ? x : y)
typedef int (*MaxSubarrayFunc)(int* nums, int numsSize);

// MARK:- 动态规划
int maxSubArray(int* nums, int numsSize){
    if (numsSize <= 0) {
        return 0;
    }
    // 当前最大值
    int currentSum = nums[0];
    // 历史最大值
    int max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        /*
         判断合并当前元素后，和的变化趋势：和大于当前元素，将合并后的值跟 max 比较，保留较大值；如果小于当前值，将当前值和 max 比较，保留较大者。
         */
        currentSum = MAX(currentSum + nums[i], nums[i]);
        max = MAX(max, currentSum);
    }
    
    return max;
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
 nums = {-2,1,-3,4,-1,2,1,-5,4}
 numsSize = 9
 result = 6
 */
void testMaxSubarray1(MaxSubarrayFunc func) {
    const int length = 9;
    int nums[length] = {-2,1,-3,4,-1,2,1,-5,4};
    int result = func(nums, length);
    printArray(nums, length);
    printf("result: %d\n", result);
    printf("\n");
}

/**
 nums = {0}
 numsSize = 1
 result = 0
 */
void testMaxSubarray2(MaxSubarrayFunc func) {
    const int length = 1;
    int nums[length] = {0};
    int result = func(nums, length);
    printArray(nums, length);
    printf("result: %d\n", result);
    printf("\n");
}

/**
 nums = {1, 2, 3, 4, 5}
 numsSize = 5
 result = 15
 */
void testMaxSubarray3(MaxSubarrayFunc func) {
    const int length = 5;
    int nums[length] = {1, 2, 3, 4, 5};
    int result = func(nums, length);
    printArray(nums, length);
    printf("result: %d\n", result);
    printf("\n");
}

/**
 nums = {1, 2}
 numsSize = 2
 result = 3
 */
void testMaxSubarray4(MaxSubarrayFunc func) {
    const int length = 2;
    int nums[length] = {1, 2};
    int result = func(nums, length);
    printArray(nums, length);
    printf("result: %d\n", result);
    printf("\n");
}

void testMaxSubarray(void) {
    testMaxSubarray1(maxSubArray);
    testMaxSubarray2(maxSubArray);
    testMaxSubarray3(maxSubArray);
    testMaxSubarray4(maxSubArray);
}
