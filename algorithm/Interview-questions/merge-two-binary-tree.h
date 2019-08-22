//
//  merge-two-binary-tree.h
//  algorithm
//
//  Created by Kai on 2019/8/22.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef merge_two_binary_tree_h
#define merge_two_binary_tree_h

/*
 合并两颗二叉树
    * 相同位置的节点值相加作为新树节点
    * 相同位置的节点有一个为空，则将另一个节点作为新树节点
 */

#include <stdio.h>
#include "binary-tree.h"

void mergeTwoBinaryTree(TreeNode *tree1, TreeNode *tree2, TreeNode **mergedTree);

// MARK:- 测试
void testMergeTwoBinaryTree(void);

#endif /* merge_two_binary_tree_h */
