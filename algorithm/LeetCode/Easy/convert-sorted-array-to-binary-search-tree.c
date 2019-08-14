//
//  convert-sorted-array-to-binary-search-tree.c
//  algorithm
//
//  Created by Kai on 2019/8/14.
//  Copyright © 2019 kai. All rights reserved.
//

#include "convert-sorted-array-to-binary-search-tree.h"
#include <stdlib.h>
#include "question-32.h"

/*
 https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 */

TreeNode *sortedArrayToBSTCore(int *nums, int start, int end);

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (nums == NULL || numsSize <= 0) return NULL;
    TreeNode *tree = sortedArrayToBSTCore(nums, 0, numsSize - 1);
    return tree;
}

TreeNode *sortedArrayToBSTCore(int *nums, int start, int end) {
    int mid = (start + end) >> 1;
    TreeNode *current = malloc(sizeof(TreeNode));
    current->val = nums[mid];
    current->left = NULL;
    current->right = NULL;
    
    if (start != mid) current->left = sortedArrayToBSTCore(nums, start, mid - 1);
    if (end != mid) current->right = sortedArrayToBSTCore(nums, mid + 1, end);
    
    return current;
}

// MARK:- 测试

void testSortedArrayToBST1(void) {
    const int length = 5;
    int nums[length] = {-10, -3, 1, 5, 9};
    TreeNode *tree = sortedArrayToBST(nums, length);
    printf("二叉排序树如下：\n");
    printBinaryTreeInLevelOrderWithWrap(tree);
}

void testSortedArrayToBST2(void) {
    const int length = 1;
    int nums[length] = {23};
    TreeNode *tree = sortedArrayToBST(nums, length);
    printf("二叉排序树如下：\n");
    printBinaryTreeInLevelOrderWithWrap(tree);
}

void testSortedArrayToBST(void) {
    testSortedArrayToBST1();
    testSortedArrayToBST2();
}
