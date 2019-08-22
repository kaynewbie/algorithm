//
//  array-k-equal-division.h
//  algorithm
//
//  Created by Kai on 2019/8/23.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef array_k_equal_division_h
#define array_k_equal_division_h

/*
 数组元素和是否支持 k 等分
 */

#include <stdio.h>
#include <stdbool.h>


/**
 数组元素和 k 等分，意味着数组整体的和是 k 的倍数。遍历数组，找出 k 份总和为 sum/k 的子数组。

 @param nums 数组
 @param len 长度
 @param k 等分成 k 份
 @return 数组是否支持等分 k 份
 */
bool arrayCanBeKEqualDivision(int *nums, int len, int k);

// MARK:- 测试
void testArrayCanBeKEqualDivision(void);

#endif /* array_k_equal_division_h */
