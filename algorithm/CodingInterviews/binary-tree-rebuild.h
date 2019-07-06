//
//  binary-tree-rebuild.h
//  algorithm
//
//  Created by Kai on 2019/7/6.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef binary_tree_rebuild_h
#define binary_tree_rebuild_h

#include <stdio.h>
#include "binary-tree-iterate.h"

/**
 给出二叉树的前序遍历和中序遍历，还原二叉树，二叉树节点元素都不相同。

 @param preOrder 先序遍历
 @param inOrder 中序遍历
 @param length 二叉树节点数量
 @return 还原后的二叉树根节点
 */
Node *rebuildBinaryTree(int preOrder[], int inOrder[], int length);
void testRebuildBinaryTree(void);

#endif /* binary_tree_rebuild_h */
