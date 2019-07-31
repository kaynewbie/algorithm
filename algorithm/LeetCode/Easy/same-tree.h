//
//  same-tree.h
//  algorithm
//
//  Created by Kai on 2019/7/30.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef same_tree_h
#define same_tree_h

#include <stdio.h>
#include "stdbool.h"
#include "binary-tree.h"

/**
 两颗树是否相等
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q);

void testIsSameTree(void);

#endif /* same_tree_h */
