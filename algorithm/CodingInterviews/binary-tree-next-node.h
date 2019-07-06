//
//  binary-tree-next-node.h
//  algorithm
//
//  Created by Kai on 2019/7/7.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef binary_tree_next_node_h
#define binary_tree_next_node_h

#include <stdio.h>

/**
 数节点的数据结构，每个节点三个指针，分别指向左子节点、右子节点和父节点。
 */
typedef struct TripleDirectionNode {
    int value;
    struct TripleDirectionNode *left;
    struct TripleDirectionNode *right;
    struct TripleDirectionNode *parent;
}TripleDirectionNode;

/**
 寻找树的中序遍历的下一个节点

 @param tree 当前节点
 @return 当前节点中序遍历要访问的下一个节点。
 */
TripleDirectionNode *nextNodeInOrder(TripleDirectionNode *tree);
void testNextNodeInOrder(void);

#endif /* binary_tree_next_node_h */
