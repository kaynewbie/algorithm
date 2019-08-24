//
//  question-32.c
//  algorithm
//
//  Created by Kai on 2019/8/20.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-32.h"
#include "queue.h"
#include "stack.h"

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

/*
 层序遍历打印二叉树，且按照 S 型打印：奇数层从左往右打印，偶数层从右往左打印
 
 借助两个栈实现，奇数层入栈顺序从右往左，偶数层入栈顺序从左往右
 */
void printBinaryTreeInLevelOrderInS(TreeNode *tree) {
    Stack *oddStack = createStack(sizeof(TreeNode), 20);// 偶数层栈
    Stack *evenStack = createStack(sizeof(TreeNode), 20);// 奇数层栈
    
    int toBePrint;// 当前层剩余需要打印的节点数
    int nextLevelCount;// 下一层节点数
    int oddOrEven;// 表示当前层是奇数层还是偶数层，0 表示偶数层，1表示奇数层
    Stack *currentStack;// 当前层需要打印的元素所在的栈
    Stack *nextStack;// 下一层元素入栈所需的栈
    
    oddOrEven = 1;
    nextLevelCount = 0;
    toBePrint = 1;
    stackPush(oddStack, tree);
    
    do {
        TreeNode *currentNode = malloc(sizeof(TreeNode));
        currentStack = oddOrEven == 0 ? evenStack : oddStack;
        nextStack = oddOrEven == 0 ? oddStack : evenStack;
        stackPop(currentStack, currentNode);
        // 打印当前元素值
        printf("%d ", currentNode->val);
        // 下一层元素入栈
        stackPush(nextStack, oddOrEven == 0 ? currentNode->right : currentNode->left);
        stackPush(nextStack, oddOrEven == 0 ? currentNode->left : currentNode->right);
        
        if (currentStack->top < 0) {// 当前层打印结束
            printf("\n");
            oddOrEven ^= 1;// 切换层次
        }
    } while ((oddStack->top >= 0) || (evenStack->top >= 0));
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

// MARK:- 测试方法三

void testPrintBinaryTreeInLevelOrderInS1(void) {
    const int length = 15;
    int nums[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    TreeNode *tree = createBinaryTree(nums, length);
    printf("二叉树层序遍历：\n");
    printBinaryTreeInLevelOrderInS(tree);
}

void testPrintBinaryTreeInLevelOrderInS2(void) {
    const int length = 13;
    int nums[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    TreeNode *tree = createBinaryTree(nums, length);
    printf("二叉树层序遍历：\n");
    printBinaryTreeInLevelOrderInS(tree);
}

void testPrintBinaryTreeInLevelOrderInS(void) {
    testPrintBinaryTreeInLevelOrderInS1();
    testPrintBinaryTreeInLevelOrderInS2();
}
