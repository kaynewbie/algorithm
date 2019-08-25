//
//  binary-tree-level-order-traversal-2.c
//  algorithm
//
//  Created by Kai on 2019/8/1.
//  Copyright © 2019 kai. All rights reserved.
//

#include "binary-tree-level-order-traversal-2.h"
#include <stdlib.h>
#include <math.h>

/*
 https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(x, y) ((x > y) ? x : y)
int height(TreeNode *);
void traversal(TreeNode *, int, int *, int *);

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int h = height(root);
    int **array = malloc(sizeof(int *) * h);
    
    *returnSize = h;
    for (int i = h; i > 0; i--) {
        int *sizeForEachLevel = calloc(1, sizeof(int));
        int *elements = malloc(sizeof(int) * (int)pow(2, i - 1));
        traversal(root, i, sizeForEachLevel, elements);
        array[h - i] = elements;
        returnColumnSizes[h - i] = sizeForEachLevel;
    }
    
    return array;
}

// 遍历树，获取节点数据
void traversal(TreeNode *tree, int level, int *levelSize, int *elements) {
    if (tree == NULL) return;
    if (level == 1) {
        elements[*levelSize] = tree->val;
        *levelSize += 1;
    } else {
        traversal(tree->left, level - 1, levelSize, elements);
        traversal(tree->right, level - 1, levelSize, elements);
    }
}

// 获取数的高度
int height(TreeNode *tree) {
    if (tree == NULL) return 0;
    int lHeight = height(tree->left);
    int rHeight = height(tree->right);
    return MAX(lHeight, rHeight) + 1;
}

// MARK:- Test

void printReturnColumnSizes(int size, int **returnColumnSizes) {
    printf("returnColumnSizes: ");
    for (int i = 0; i < size; i++) {
        int *tmp = returnColumnSizes[0];
        printf("%d ", *tmp);
    }
    printf("\n");
}

void printResult(int **result, int size, int **returnColumnSizes) {
    printf("result: ");
    
    for (int i = 0; i < size; i++) {
        int *levelSize = returnColumnSizes[i];
        int *levelEles = result[i];
        for (int j = 0; j < *levelSize; j++) {
            int ele = levelEles[j];
            printf("%d ", ele);
        }
    }
    
    printf("\n");
}

void testLevelOrderBottom1(void) {
    const int length = 7;
    int elements[length] = { 3, 9, 20, 0, 0, 15, 7};
    TreeNode *tree = createBinaryTree(elements, length);
    printf("tree: ");
    preOrderRecursive(tree);
    printf("\n");
    
    int size = 0;
    int **returnColumnSizes = calloc(10, sizeof(int *));
    int **result = levelOrderBottom(tree, &size, returnColumnSizes);
    
    printReturnColumnSizes(size, returnColumnSizes);
    printResult(result, size, returnColumnSizes);
}

void testLevelOrderBottom(void) {
    testLevelOrderBottom1();
}
