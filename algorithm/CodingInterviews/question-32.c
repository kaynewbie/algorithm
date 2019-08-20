//
//  question-32.c
//  algorithm
//
//  Created by Kai on 2019/8/20.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-32.h"
#include "queue.h"

void printBinaryTreeInLevelOrder(TreeNode *tree) {
    TreeNode *node;
    queue_t *q;
    
    node = NULL;
    q = queue_create();
    queue_put(q, tree);// 将跟节点入队
    do {
        queue_get(q, (void **)&node);
        printf("%d ", node->val);
        
        if (node->left != NULL) {
            queue_put(q, node->left);
        }
        if (node->right != NULL) {
            queue_put(q, node->right);
        }
    } while (queue_empty(q) == 0);// 队列为空时终止循环
    printf("\n");
}

void printBinaryTreeInLevelOrderWithWrap(TreeNode *tree) {
    TreeNode *node;
    queue_t *q;
    int toBePrint;// 当前层剩余需要打印的节点数
    int nextLevelCount;// 下一层节点数
    
    node = NULL;
    nextLevelCount = 0;
    
    q = queue_create();
    queue_put(q, tree);// 将跟节点入队
    toBePrint = 1;
    
    do {
        queue_get(q, (void **)&node);
        printf("%d ", node->val);
        
        if (node->left != NULL) {
            queue_put(q, node->left);
            nextLevelCount++;
        }
        if (node->right != NULL) {
            queue_put(q, node->right);
            nextLevelCount++;
        }
        toBePrint--;
        if (toBePrint == 0) {
            printf("\n");
            toBePrint = nextLevelCount;
            nextLevelCount = 0;
        }
    } while (queue_empty(q) == 0);// 队列为空时终止循环
    printf("\n");
}

// MARK:- 测试

// MARK:- 测试方法一
void testPrintBinaryTreeInLevelOrder1(void) {
    const int length = 10;
    int nums[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TreeNode *tree = createBinaryTree(nums, length);
    printf("二叉树层序遍历： ");
    printBinaryTreeInLevelOrder(tree);
}

void testPrintBinaryTreeInLevelOrder2(void) {
    const int length = 5;
    int nums[length] = {1, 2, 0, 4, 5};
    TreeNode *tree = createBinaryTree(nums, length);
    printf("二叉树层序遍历： ");
    printBinaryTreeInLevelOrder(tree);
}

void testPrintBinaryTreeInLevelOrder(void) {
    testPrintBinaryTreeInLevelOrder1();
    testPrintBinaryTreeInLevelOrder2();
}

// MARK:- 测试方法二

void testPrintBinaryTreeInLevelOrderWithWrap1(void) {
    const int length = 10;
    int nums[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    TreeNode *tree = createBinaryTree(nums, length);
    printf("二叉树层序遍历：\n");
    printBinaryTreeInLevelOrderWithWrap(tree);
}

void testPrintBinaryTreeInLevelOrderWithWrap2(void) {
    const int length = 5;
    int nums[length] = {1, 2, 0, 4, 5};
    TreeNode *tree = createBinaryTree(nums, length);
    printf("二叉树层序遍历：\n");
    printBinaryTreeInLevelOrderWithWrap(tree);
}

void testPrintBinaryTreeInLevelOrderWithWrap(void) {
    testPrintBinaryTreeInLevelOrderWithWrap1();
    testPrintBinaryTreeInLevelOrderWithWrap2();
}
