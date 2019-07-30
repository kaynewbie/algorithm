//
//  symmetric-tree.c
//  algorithm
//
//  Created by Kai on 2019/7/30.
//  Copyright © 2019 kai. All rights reserved.
//

#include "symmetric-tree.h"
#include "stdbool.h"
#include "binary-tree.h"

/*
 https://leetcode.com/problems/symmetric-tree/
 */

bool isSymmetricTree(struct TreeNode* p, struct TreeNode* q);
bool isSymmetric(struct TreeNode* root){
    if (root == NULL) {
        return true;
    }
    return isSymmetricTree(root->left, root->right);
}

bool isSymmetricTree(struct TreeNode* p, struct TreeNode* q){
    if ((p == NULL ^ q == NULL) == 1) {
        return false;
    }
    if (p == NULL & q == NULL) {
        return true;
    }
    return (p->val == q->val)
    && isSymmetricTree(p->left, q->right)
    && isSymmetricTree(p->right, q->left);
}
