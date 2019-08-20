//
//  question-32.h
//  algorithm
//
//  Created by Kai on 2019/8/20.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef question_32_h
#define question_32_h

/*
 从上到下打印二叉树
 */

#include <stdio.h>
#include "binary-tree.h"


/**
 层序遍历打印二叉树，层级之间 **不会换行**。借助辅助队列，循环从队列取出节点，将取出的节点左右子节点分别入队，直到队列为空。

 @param tree 二叉树根节点指针
 */
void printBinaryTreeInLevelOrder(TreeNode *tree);

/**
 层序遍历打印二叉树，层级之间 **会换行**。借助辅助队列，循环从队列取出节点，将取出的节点左右子节点分别入队，直到队列为空。
 
 @param tree 二叉树根节点指针
 */
void printBinaryTreeInLevelOrderWithWrap(TreeNode *tree);

// MARK:- 测试
void testPrintBinaryTreeInLevelOrder(void);
void testPrintBinaryTreeInLevelOrderWithWrap(void);

#endif /* question_32_h */
