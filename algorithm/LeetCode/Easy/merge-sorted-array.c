//
//  merge-sorted-array.c
//  algorithm
//
//  Created by Kai on 2019/7/29.
//  Copyright © 2019 kai. All rights reserved.
//

#include "merge-sorted-array.h"

/*
 https://leetcode.com/problems/merge-sorted-array/
 */

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int idxInResult, idxInNum1, idxInNum2;
    
    idxInResult = m + n - 1;
    idxInNum1 = m - 1;
    idxInNum2 = n - 1;
    
    while (idxInResult >= 0) {
        if (idxInNum1 < 0) {
            nums1[idxInResult] = nums2[idxInNum2];
            idxInNum2--;
        } else if (idxInNum2 < 0) {
            nums1[idxInResult] = nums1[idxInNum1];
            idxInNum1--;
        } else {
            if (nums1[idxInNum1] >= nums2[idxInNum2]) {
                nums1[idxInResult] = nums1[idxInNum1];
                idxInNum1--;
            } else {
                nums1[idxInResult] = nums2[idxInNum2];
                idxInNum2--;
            }
        }
        idxInResult--;
    }
}

// MARK:- Test
static void printArray(int *num, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", num[i]);
    }
}

/*
 nums1 = {1, 2, 3}
 nums2 = {2, 5, 6}
 */
void testMergeSortedArray1(void) {
    const int length1 = 3;
    const int length2 = 3;
    int nums1[100] = {1, 2, 3};
    int nums2[length1] = {2, 5, 6};
    merge(nums1, 100, length1, nums2, length2, length2);
    printArray(nums1, length1 + length2);
}

/*
 nums1 = {-1,0,0,3,3,3}
 nums2 = {1,2,2}
 */
void testMergeSortedArray2(void) {
    const int length1 = 6;
    const int length2 = 3;
    int nums1[100] = {-1,0,0,3,3,3};
    int nums2[length1] = {2, 5, 6};
    merge(nums1, 100, length1, nums2, length2, length2);
    printArray(nums1, length1 + length2);
}

void testMergeSortedArray(void) {
//    testMergeSortedArray1();
    testMergeSortedArray2();
}
