//
//  remove-duplicates-from-sorted-array.c
//  algorithm
//
//  Created by Kai on 2019/7/23.
//  Copyright © 2019 kai. All rights reserved.
//

#include "remove-duplicates-from-sorted-array.h"
#include "stdbool.h"

/*
 https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

bool isDuplicates(int *nums, int numsSize, int target);

// MARK:- 适用 有序/无序 的数组
/**
 时间复杂度：O(n2)，空间复杂度：O(1)
 选择第一个元素为标记值，将重复的元素都置为该值
 从第二个元素开始遍历，从之前的元素中检查是否已存在当前值：存在就置为标记值再继续遍历；不存在则继续遍历
 遍历过程中记录不重复的元素数量，记为 m
 最后遍历数组，将非标记值且不是第一个元素的元素写入到 m 中
 */
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return 0;
    }
    int length = 1;
    int markValue = nums[0];
    bool isDuplicate;
    for (int i = 1; i < numsSize; i++) {
        isDuplicate = isDuplicates(nums, i, nums[i]);
        if (isDuplicate) {
            nums[i] = markValue;
        } else {
            ++length;
        }
    }
    int idx = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != markValue) {
            nums[idx] = nums[i];
            ++idx;
        }
    }
    return length;
}

/**
 从之前的数组中，检查 target 是否已经存在
 */
bool isDuplicates(int *nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            return true;
        }
    }
    return false;
}

static void printArray(int *num, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", num[i]);
    }
}

/**
 nums = {1, 1, 2, 3}
 numsSize = 4
 result = 3
 */
void testRemoveDuplicates1(void) {
    const int length = 4;
    int nums[length] = {1, 1, 2, 3};
    int result = removeDuplicates(nums, length);
    printf("original: ");
    printArray(nums, length);
    printf("\nresult length: %d\n", result);
    printf("after remove duplication: ");
    printArray(nums, result);
    printf("\n-------------\n");
}

/**
 nums = {1, 2, 2, 3}
 numsSize = 4
 result = 3
 */
void testRemoveDuplicates2(void) {
    const int length = 4;
    int nums[length] = {1, 2, 2, 3};
    int result = removeDuplicates(nums, length);
    printf("original: ");
    printArray(nums, length);
    printf("\nresult length: %d\n", result);
    printf("after remove duplication: ");
    printArray(nums, result);
    printf("\n-------------\n");
}

/**
 nums = {1, 2, 3, 3}
 numsSize = 4
 result = 3
 */
void testRemoveDuplicates3(void) {
    const int length = 4;
    int nums[length] = {1, 2, 3, 3};
    int result = removeDuplicates(nums, length);
    printf("original: ");
    printArray(nums, length);
    printf("\nresult length: %d\n", result);
    printf("after remove duplication: ");
    printArray(nums, result);
    printf("\n-------------\n");
}

/**
 nums = {1, 1, 2, 2, 3, 3}
 numsSize = 6
 result = 3
 */
void testRemoveDuplicates4(void) {
    const int length = 6;
    int nums[length] = {1, 1, 2, 2, 3, 3};
    int result = removeDuplicates(nums, length);
    printf("original: ");
    printArray(nums, length);
    printf("\nresult length: %d\n", result);
    printf("after remove duplication: ");
    printArray(nums, result);
    printf("\n-------------\n");
}

/**
 nums = {1, 1, 2, 2, 3, 3, 3, 3}
 numsSize = 8
 result = 3
 */
void testRemoveDuplicates5(void) {
    const int length = 8;
    int nums[length] = {1, 1, 2, 2, 3, 3, 3, 3};
    int result = removeDuplicates(nums, length);
    printf("original: ");
    printArray(nums, length);
    printf("\nresult length: %d\n", result);
    printf("after remove duplication: ");
    printArray(nums, result);
    printf("\n-------------\n");
}

/**
 nums = {1, 1, 1, 1, 1, 1}
 numsSize = 6
 result = 1
 */
void testRemoveDuplicates6(void) {
    const int length = 6;
    int nums[length] = {1, 1, 1, 1, 1, 1};
    int result = removeDuplicates(nums, length);
    printf("original: ");
    printArray(nums, length);
    printf("\nresult length: %d\n", result);
    printf("after remove duplication: ");
    printArray(nums, result);
    printf("\n-------------\n");
}

/**
 nums = {}
 numsSize = 0
 result = 0
 */
void testRemoveDuplicates7(void) {
    const int length = 0;
    int nums[length] = {};
    int result = removeDuplicates(nums, length);
    printf("original: ");
    printArray(nums, length);
    printf("\nresult length: %d\n", result);
    printf("after remove duplication: ");
    printArray(nums, result);
    printf("\n-------------\n");
}

void testRemoveDuplicates(void) {
    testRemoveDuplicates1();
    testRemoveDuplicates2();
    testRemoveDuplicates3();
    testRemoveDuplicates4();
    testRemoveDuplicates5();
    testRemoveDuplicates6();
    testRemoveDuplicates7();
}
