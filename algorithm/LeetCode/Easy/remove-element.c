//
//  remove-element.c
//  algorithm
//
//  Created by Kai on 2019/7/23.
//  Copyright © 2019 kai. All rights reserved.
//

#include "remove-element.h"
#include "stdbool.h"

/*
 https://leetcode.com/problems/remove-element/
 */


/**
 时间复杂度：O(n)，空间复杂度：O(1)
 */
int removeElement(int* nums, int numsSize, int val) {
    if (numsSize <= 0) {
        return 0;
    }
    int idx = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[idx] = nums[i];
            ++idx;
        }
    }
    return idx;
}

static void printArray(int *num, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", num[i]);
    }
}

/**
 nums = {3,2,2,3}, val = 3
 length = 2, array = {2, 2}
 */
void testRemoveElement1() {
    const int length = 4;
    int nums[length] = {3,2,2,3};
    int val = 3;
    printf("original: ");
    printArray(nums, length);
    printf("\nremove: %d", val);
    int result = removeElement(nums, length, val);
    printf("\nresult length: %d\n", result);
    printf("after remove element: ");
    printArray(nums, result);
    printf("\n-------------\n");
}

/**
 nums = {0,1,2,2,3,0,4,2}, val = 2
 length = 5, array = {0, 1, 3, 0, 4}
 */
void testRemoveElement2() {
    const int length = 8;
    int nums[length] = {0,1,2,2,3,0,4,2};
    int val = 2;
    printf("original: ");
    printArray(nums, length);
    printf("\nremove: %d", val);
    int result = removeElement(nums, length, val);
    printf("\nresult length: %d\n", result);
    printf("after remove element: ");
    printArray(nums, result);
    printf("\n-------------\n");
}

/**
 nums = {2,1,2,2,3,0,4,2}, val = 2
 length = 4, array = {1, 3, 0, 4}
 */
void testRemoveElement3() {
    const int length = 8;
    int nums[length] = {2,1,2,2,3,0,4,2};
    int val = 2;
    printf("original: ");
    printArray(nums, length);
    printf("\nremove: %d", val);
    int result = removeElement(nums, length, val);
    printf("\nresult length: %d\n", result);
    printf("after remove element: ");
    printArray(nums, result);
    printf("\n-------------\n");
}

/**
 nums = {}, val = 2
 length = 0, array = {}
 */
void testRemoveElement4() {
    const int length = 0;
    int nums[length] = {};
    int val = 2;
    printf("original: ");
    printArray(nums, length);
    printf("\nremove: %d", val);
    int result = removeElement(nums, length, val);
    printf("\nresult length: %d\n", result);
    printf("after remove element: ");
    printArray(nums, result);
    printf("\n-------------\n");
}

void testRemoveElement(void) {
    testRemoveElement1();
    testRemoveElement2();
    testRemoveElement3();
    testRemoveElement4();
}
