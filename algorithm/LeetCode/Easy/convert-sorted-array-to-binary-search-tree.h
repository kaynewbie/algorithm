//
//  convert-sorted-array-to-binary-search-tree.h
//  algorithm
//
//  Created by Kai on 2019/8/14.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef convert_sorted_array_to_binary_search_tree_h
#define convert_sorted_array_to_binary_search_tree_h

#include <stdio.h>
#include "binary-tree.h"


/**
 将排序数组转成二叉排序树，且树是平衡的，即，最高和最低节点高度差为1
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize);

// MARK:- 测试

void testSortedArrayToBST(void);

#endif /* convert_sorted_array_to_binary_search_tree_h */
