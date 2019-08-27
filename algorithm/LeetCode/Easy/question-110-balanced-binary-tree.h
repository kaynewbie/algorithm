//
//  question-110-balanced-binary-tree.h
//  algorithm
//
//  Created by Kai on 2019/8/27.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef question_110_balanced_binary_tree_h
#define question_110_balanced_binary_tree_h

/*
 题目地址：https://leetcode.com/problems/balanced-binary-tree/
 */

#include <stdio.h>
#include <stdbool.h>
#include "binary-tree.h"

bool isBalanced(struct TreeNode* root);

// MARK:- 测试
void testIsBalanced(void);

#endif /* question_110_balanced_binary_tree_h */
