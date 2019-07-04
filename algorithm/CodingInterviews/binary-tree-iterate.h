//
//  binary-tree-iterate.h
//  algorithm
//
//  Created by Kai on 2019/7/4.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef binary_tree_iterate_h
#define binary_tree_iterate_h

#include <stdio.h>

/**
 树节点结构定义
 */
typedef struct Node {
    int value;
    struct Node *leftChild;
    struct Node *rightChild;
}Node;

void testPreOrderCycle(void);

#endif /* binary_tree_iterate_h */
