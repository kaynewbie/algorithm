//
//  question-110-balanced-binary-tree.c
//  algorithm
//
//  Created by Kai on 2019/8/27.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-110-balanced-binary-tree.h"
#include <stdlib.h>

bool isBalancedCore(struct TreeNode* root);

// 注意：每个节点子树高度差小于等于1，测试用例4（testIsBalanced4）中，最大和最小高度差2，但是子树最大高度差是1。
bool isBalanced(struct TreeNode* root) {
    return isBalancedCore(root);
}

bool isBalancedCore(struct TreeNode* root) {
    if (root == NULL) return true;
    int leftMax = maxDepth(root->left);
    int rightMax = maxDepth(root->right);
    return abs(leftMax - rightMax) <= 1
    && isBalancedCore(root->left)
    && isBalancedCore(root->right);
}

// MARK:- 测试

void testIsBalanced1(void) {
    const int length = 7;
    int nums[length] = {3,9,20,0,0,15,7};
    TreeNode *tree = createBinaryTree(nums, length);
    bool result = isBalanced(tree);
    printf("%s is%s balanced tree\n", __func__, result ? "" : " NOT");
}

void testIsBalanced2(void) {
    const int length = 9;
    int nums[length] = {1,2,2,3,3,0,0,4,4};
    TreeNode *tree = createBinaryTree(nums, length);
    bool result = isBalanced(tree);
    printf("%s is%s balanced tree\n", __func__, result ? "" : " NOT");
}

void testIsBalanced3(void) {
    const int length = 1;
    int nums[length] = {1};
    TreeNode *tree = createBinaryTree(nums, length);
    bool result = isBalanced(tree);
    printf("%s is%s balanced tree\n", __func__, result ? "" : " NOT");
}

void testIsBalanced4(void) {
    const int length = 17;
    int nums[length] = {1,2,2,3,3,3,3,4,4,4,4,4,4,0,0,5,5};
    TreeNode *tree = createBinaryTree(nums, length);
    bool result = isBalanced(tree);
    printf("%s is%s balanced tree\n", __func__, result ? "" : " NOT");
}

void testIsBalanced5(void) {
    const int length = 8;
    int nums[length] = {1, 2, 5, 3, 0, 0, 0, 4};
    TreeNode *tree = createBinaryTree(nums, length);
    bool result = isBalanced(tree);
    printf("%s is%s balanced tree\n", __func__, result ? "" : " NOT");
}

void testIsBalanced(void) {
    testIsBalanced1();
    testIsBalanced2();
    testIsBalanced3();
    testIsBalanced4();
    testIsBalanced5();
}
