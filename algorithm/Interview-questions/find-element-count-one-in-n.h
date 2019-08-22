//
//  find-element-count-one-in-n.h
//  algorithm
//
//  Created by Kai on 2019/8/21.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef find_element_count_one_in_n_h
#define find_element_count_one_in_n_h

/*
 找到数组中超过 1/n 的元素。如，1/2, 1/3...
 */

#include <stdio.h>

/**
 找到数组中超过 1/n 的元素。如，1/2, 1/3...

 @param array 目标数组
 @param length 数组长度
 @param n 数组n等分
 @param count 最后找到超过 1/n 的元素数量
 @return 最后找到超过 1/n 的元素数组
 */
int *findElementsCountMoreThanOneInN(int *array, int length, int n, int *count);

// MARK:- 测试
void testCreateMap(void);
void testFindElementsCountMoreThanOneInN(void);

#endif /* find_element_count_one_in_n_h */
