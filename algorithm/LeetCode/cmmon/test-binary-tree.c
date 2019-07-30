//
//  test-binary-tree.c
//  algorithm
//
//  Created by Kai on 2019/7/30.
//  Copyright © 2019 kai. All rights reserved.
//

#include "test-binary-tree.h"
#include "binary-tree.h"

/*
 用于测试 binary tree 的构造
 */

void testCreateBinaryTree1(void) {
    const int length = 10;
    int nums[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TreeNode *head = createBinaryTree(nums, length);
    printf("tree: ");
    preOrderRecursive(head);
    printf("\n");
}

void testCreateBinaryTree2(void) {
    const int length = 10;
    int nums[length] = {1, 2, 3, 0, 5, 6, 7, 8, 9, 10};
    TreeNode *head = createBinaryTree(nums, length);
    printf("tree: ");
    preOrderRecursive(head);
    printf("\n");
}

void testBinaryTree(void) {
    testCreateBinaryTree1();
    testCreateBinaryTree2();
}
