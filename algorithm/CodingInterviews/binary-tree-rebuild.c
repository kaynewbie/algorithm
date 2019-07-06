//
//  binary-tree-rebuild.c
//  algorithm
//
//  Created by Kai on 2019/7/6.
//  Copyright © 2019 kai. All rights reserved.
//

#include "binary-tree-rebuild.h"
#include "stdlib.h"
#include "stdbool.h"

/**
 分析：先序遍历父节点在第一个位置；中序遍历左子树在父节点左边，右子树在父节点右边。
 递归，分治。
 */
Node *rebuildBinaryTree(int preOrder[], int inOrder[], int length) {
    if (preOrder == NULL || inOrder == NULL) {
        return NULL;
    }
    int parentValue = preOrder[0];
    
    Node *parentNode = (Node *)malloc(sizeof(Node));
    parentNode->value = parentValue;
    
    // 边界情况：先序遍历和中序遍历数组不一致。
    bool valid = false;
    for (int i = 0; i < length; i++) {
        if (inOrder[i] == parentValue) {
            valid = true;
            
            Node *left = NULL, *right = NULL;
            
            if (i > 0) {
                left = rebuildBinaryTree(preOrder+1, inOrder, i);
            }
            if (i < length - 1) {
                right = rebuildBinaryTree(preOrder+i+1, inOrder+i+1, length-i-1);
            }
            parentNode->leftChild = left;
            parentNode->rightChild = right;
            break;
        }
    }
    if (!valid) {
        return NULL;
    }
    return parentNode;
}
void testRebuildBinaryTree() {
    const int length = 10;
    int preOrder[length] = {1, 2, 4, 5, 6, 7, 9, 10, 3, 8};
    int inOrder[length] = {4, 2, 6, 5, 9, 10, 7, 1, 8, 3};
//    int *preOrder = NULL;
//    int *inOrder = NULL;
    
    Node *tree = rebuildBinaryTree(preOrder, inOrder, length);
    
    postOrderRecursive(tree);
}
