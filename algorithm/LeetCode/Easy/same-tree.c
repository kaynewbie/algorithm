
//
//  same-tree.c
//  algorithm
//
//  Created by Kai on 2019/7/30.
//  Copyright © 2019 kai. All rights reserved.
//

#include "same-tree.h"

/*
 https://leetcode.com/problems/same-tree/
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if ((p == NULL ^ q == NULL) == 1) {
        return false;
    }
    if (p == NULL & q == NULL) {
        return true;
    }
    return (p->val == q->val)
    && isSameTree(p->left, q->left)
    && isSameTree(p->right, q->right);
}

// MARK: Test
#include "stdlib.h"

typedef struct TreeNode TreeNode;

/**
 创建二叉树
 */
TreeNode *createATree1() {
    TreeNode *node1 = malloc(sizeof(TreeNode));
    node1->val = 1;
    TreeNode *node2 = malloc(sizeof(TreeNode));
    node2->val = 2;
    TreeNode *node3 = malloc(sizeof(TreeNode));
    node3->val = 3;
    node1->left = node2;
    node1->right = node3;
    node2->left = NULL;
    node2->right = NULL;
    node3->left = NULL;
    node3->right = NULL;
    return node1;
}

/**
 前序遍历打印二叉树
 */
static void preOrderRecursive(TreeNode *tree) {
    if (tree == NULL) {
        return;
    }
    char *format = "%d ";
    printf(format, tree->val);
    preOrderRecursive(tree->left);
    preOrderRecursive(tree->right);
}

/*
  1     1
 2 3   2 3
 */
void testIsSameTree1(void) {
    TreeNode *tree1 = createATree1();
    TreeNode *tree2 = createATree1();
    bool result = isSameTree(tree1, tree2);
    
    printf("tree: ");
    preOrderRecursive(tree1);
    printf("\n");
    printf("tree: ");
    preOrderRecursive(tree2);
    printf("\n");
    printf("is same: %d\n", result);
}

TreeNode *createATree2() {
    TreeNode *node1 = malloc(sizeof(TreeNode));
    node1->val = 1;
    TreeNode *node2 = malloc(sizeof(TreeNode));
    node2->val = 2;
    TreeNode *node3 = malloc(sizeof(TreeNode));
    node3->val = 3;
    node1->left = node2;
    node1->right = node3;
    node2->left = NULL;
    node2->right = NULL;
    node3->left = NULL;
    node3->right = NULL;
    return node1;
}

/*
  1     1
   2   1 2
 */
void testIsSameTree2(void) {
    
}

void testIsSameTree(void) {
    testIsSameTree1();
}
