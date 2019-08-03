//
//  question-26.c
//  algorithm
//
//  Created by Kai on 2019/8/3.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-26.h"
#include "binary-tree.h"
#include "stdbool.h"

/*
 树的子结构
 输入两颗树，A 和 B，判断 B 是否 A 的子树
 */

bool isSubtreeCore(TreeNode *, TreeNode *);

/*
 1. 遍历 t1，找到等于 t2 根节点的节点 R
 2. 再遍历 t2，确定 R 子树中相同的结构
 */
bool isSubtree(TreeNode *t1, TreeNode *t2) {
    if (t1 == NULL || t2 == NULL) return false;
    
    if (t1->val == t2->val)
        if (isSubtreeCore(t1, t2))
            return true;
    return isSubtree(t1->left, t2) || isSubtree(t1->right, t2);
}

bool isSubtreeCore(TreeNode *t1, TreeNode *t2) {
    if (t1 == NULL) return true;
    if (t2 == NULL) return false;
    
    return t1->val == t2->val
    && isSubtreeCore(t1->left, t2->left)
    && isSubtreeCore(t2->right, t2->right);
}

/*
 t1 = [8, 8, 7, 9, 2, 0, 0, 0, 0, 5, 7]
 t2 = [8, 9, 2]
 */
void testIsSubtree1(void) {
    int num1[11] = {8, 8, 7, 9, 2, 0, 0, 0, 0, 5, 7};
    TreeNode *t1 = createBinaryTree(num1, 11);
    int num2[3] = {8, 9, 2};
    TreeNode *t2 = createBinaryTree(num2, 3);
    printf("tree1: ");
    preOrderRecursive(t1);
    printf("\n");
    printf("tree2: ");
    preOrderRecursive(t2);
    printf("\n");
    
    bool result = isSubtree(t1, t2);
    printf("t1 %s subtree t2", result ? "has" : "has not");
}

/*
 t1 = [8, 8, 7, 9, 2, 0, 0, 0, 0, 5, 7]
 t2 = [8, 9, 2]
 */
void testIsSubtree2(void) {
    int num1[11] = {8, 8, 7, 9, 2, 0, 0, 0, 0, 5, 7};
    TreeNode *t1 = createBinaryTree(num1, 11);
    int num2[3] = {8, 9, 2};
    TreeNode *t2 = createBinaryTree(num2, 3);
    printf("tree1: ");
    preOrderRecursive(t1);
    printf("\n");
    printf("tree2: ");
    preOrderRecursive(t2);
    printf("\n");
    
    bool result = isSubtree(t1, t2);
    printf("t1 %s subtree t2", result ? "has" : "has not");
}

void testIsSubtree(void) {
    testIsSubtree1();
}
