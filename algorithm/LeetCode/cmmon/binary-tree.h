//
//  binary-tree.h
//  algorithm
//
//  Created by Kai on 2019/7/30.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef binary_tree_h
#define binary_tree_h

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode TreeNode;

TreeNode *createBinaryTree(int *elements, int size);
void preOrderRecursive(TreeNode *tree);

#endif /* binary_tree_h */
