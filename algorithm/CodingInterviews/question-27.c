//
//  question-27.c
//  algorithm
//
//  Created by Kai on 2019/8/3.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-27.h"
#include "binary-tree.h"

/*
 二叉树镜像（轴对称变换）
 */

void mirrorBinary(TreeNode *tree) {
    if (tree == NULL) return;
    
    TreeNode *tmp = tree->left;
    tree->left = tree->right;
    tree->right = tmp;
    if (tree->left) mirrorBinary(tree->left);
    if (tree->right) mirrorBinary(tree->right);
}

void testMirrorBinary1(void) {
    int nums[7] = {8, 6, 10, 5, 7, 9, 11};
    TreeNode *tree = createBinaryTree(nums, 7);
    printf("original: ");
    preOrderRecursive(tree);
    printf("\n");
    
    mirrorBinary(tree);
    
    printf("mirror: ");
    preOrderRecursive(tree);
    printf("\n");
}

void testMirrorBinary2(void) {
    int nums[2] = {8, 6};
    TreeNode *tree = createBinaryTree(nums, 2);
    printf("original: ");
    preOrderRecursive(tree);
    printf("\n");
    
    mirrorBinary(tree);
    
    printf("mirror: ");
    preOrderRecursive(tree);
    printf("\n");
}

void testMirrorBinary3(void) {
    int nums[4] = {8, 3, 0, 4};
    TreeNode *tree = createBinaryTree(nums, 4);
    printf("original: ");
    preOrderRecursive(tree);
    printf("\n");
    
    mirrorBinary(tree);
    
    printf("mirror: ");
    preOrderRecursive(tree);
    printf("\n");
}

void testMirrorBinary(void) {
    testMirrorBinary1();
    testMirrorBinary2();
    testMirrorBinary3();
}
