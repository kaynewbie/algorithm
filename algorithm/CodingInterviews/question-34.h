//
//  question-34.h
//  algorithm
//
//  Created by Kai on 2019/8/25.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef question_34_h
#define question_34_h

#include <stdio.h>
#include "binary-tree.h"

/**
 二叉树中和为某一个值的所有路径（路径为从跟节点到一个叶子节点）

 @param tree 二叉树
 @param target 目标值
 */
void sumOfNodesInPathEqualsToValue(TreeNode *tree, int target);

// MARK:- 测试

void testSumOfNodesInPathEqualsToValue(void);

#endif /* question_34_h */
