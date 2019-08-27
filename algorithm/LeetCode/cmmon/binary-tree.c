//
//  binary-tree.c
//  algorithm
//
//  Created by Kai on 2019/7/30.
//  Copyright © 2019 kai. All rights reserved.
//

#include "binary-tree.h"
#include "stdlib.h"
#include "queue.h"
#include "stdbool.h"

DEFINE_Q_GET(queue_get_tree_node, TreeNode *)
#define MAX(x, y) ((x > y) ? x : y)
#define MIN(x, y) ((x < y) ? x : y)

/**
 借助队列，实现按照层序创建二叉树，元素为 0 则表示该节点为空。

 @param elements 元素数组
 @param size elements 大小
 @return 根结点指针
 */
TreeNode *createBinaryTree(int *elements, int size) {
    // 用于存放未设置子节点的节点的左右指针。每创建一个节点 n，从 q 中取出首个指针 m，将 m 指向 n，从 q 中移除 m，并将 n 的左右指针依次加入到 q 末尾。
    queue_t *q;
    TreeNode *currNode;
    TreeNode **p; // 指向指针的指针，指向某个节点的左/右指针
    TreeNode *head;
    // 当前待创建的元素索引
    int idx;

    q = queue_create();
    idx = 0;
    head = NULL;

    while (idx < size) {
        if (elements[idx] == 0) {
            currNode = NULL;
        } else {
            currNode = malloc(sizeof(TreeNode));
            currNode->val = elements[idx];
            currNode->left = NULL;
            currNode->right = NULL;
        }
        if (idx == 0) {
            head = currNode;
        }
        if (q->first_el) {
            queue_get_tree_node(q, &p);
            *p = currNode;
        }
        if (currNode != NULL) {
            queue_put(q, &(currNode->left));
            queue_put(q, &(currNode->right));
        }
        idx++;
    }
    return head;
}

int maxDepth(TreeNode *tree) {
    if (tree == NULL) return 0;
    int lHeight = maxDepth(tree->left);
    int rHeight = maxDepth(tree->right);
    return MAX(lHeight, rHeight) + 1;
}

int minDepth(TreeNode *tree) {
    if (tree == NULL) return 0;
    int lHeight = minDepth(tree->left);
    int rHeight = minDepth(tree->right);
    return MIN(lHeight, rHeight) + 1;
}

/**
 前序遍历打印二叉树
 */
void preOrderRecursive(TreeNode *tree) {
    if (tree == NULL) {
        return;
    }
    char *format = "%d ";
    printf(format, tree->val);
    preOrderRecursive(tree->left);
    preOrderRecursive(tree->right);
}

// TODO: 层序遍历，打印二叉树
