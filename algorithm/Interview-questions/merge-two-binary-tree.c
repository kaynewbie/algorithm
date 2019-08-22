//
//  merge-two-binary-tree.c
//  algorithm
//
//  Created by Kai on 2019/8/22.
//  Copyright © 2019 kai. All rights reserved.
//

#include "merge-two-binary-tree.h"
#include <stdlib.h>
#include "question-32.h"

void mergeTwoBinaryTree(TreeNode *tree1, TreeNode *tree2, TreeNode **mergedTree) {
    if (tree1 == NULL && tree2 == NULL) return;
    
    int value1, value2;
    TreeNode *newNode;
    TreeNode *tree1Left, *tree1Right;
    TreeNode *tree2Left, *tree2Right;
    
    // 取得两个树的相同位置节点值
    value1 = tree1 == NULL ? 0 : tree1->val;
    value2 = tree2 == NULL ? 0 : tree2->val;
    
    // 在当前位置为新树创建节点
    newNode = malloc(sizeof(TreeNode));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->val = value1 + value2;
    *mergedTree = newNode;
    
    // 继续递归遍历完两颗树结构
    tree1Left = tree1 == NULL ? NULL : tree1->left;
    tree1Right = tree1 == NULL ? NULL : tree1->right;
    tree2Left = tree2 == NULL ? NULL : tree2->left;
    tree2Right = tree2 == NULL ? NULL : tree2->right;
    mergeTwoBinaryTree(tree1Left, tree2Left, &(newNode->left));
    mergeTwoBinaryTree(tree1Right, tree2Right, &(newNode->right));
}

// MARK:- 测试
void testMergeTwoBinaryTree1(void) {
    const int len1 = 5;
    int array1[len1] = {1, 2, 3, 4, 5};
    TreeNode *tree1 = createBinaryTree(array1, len1);
    
    const int len2 = 5;
    int array2[len2] = {1, 2, 3, 4, 5};
    TreeNode *tree2 = createBinaryTree(array2, len2);
    
    TreeNode *mergedTree = NULL;
    mergeTwoBinaryTree(tree1, tree2, &mergedTree);
    
    printf("%s 合并完成的二叉树:\n", __func__);
    printBinaryTreeInLevelOrderWithWrap(mergedTree);
}

void testMergeTwoBinaryTree2(void) {
    const int len1 = 5;
    int array1[len1] = {1, 2, 3, 4, 5};
    TreeNode *tree1 = createBinaryTree(array1, len1);
    
    const int len2 = 10;
    int array2[len2] = {1, 2, 3, 0, 5, 6, 0, 8, 9, 10};
    TreeNode *tree2 = createBinaryTree(array2, len2);
    
    TreeNode *mergedTree = NULL;
    mergeTwoBinaryTree(tree1, tree2, &mergedTree);
    
    printf("%s 合并完成的二叉树:\n", __func__);
    printBinaryTreeInLevelOrderWithWrap(mergedTree);
}

void testMergeTwoBinaryTree(void) {
    testMergeTwoBinaryTree1();
    testMergeTwoBinaryTree2();
}
