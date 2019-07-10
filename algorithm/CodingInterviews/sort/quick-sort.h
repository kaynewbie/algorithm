//
//  quick-sort.h
//  algorithm
//
//  Created by Kai on 2019/7/11.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef quick_sort_h
#define quick_sort_h

#include <stdio.h>

/**
 获取一个随机索引，遍历数组 start 和 end-1 索引区间内的元素，
 小于等于随机索引对应的值的放到索引左边，大于的放到右边。

 @param p 数组指针
 @param start 当前排序区间起始索引
 @param end 当前排序区间终止索引
 @return 当次排序的随机索引值
 */
int partition(int *p, int start, int end);

/**
 快速排序驱动函数
 */
void quickSort(int *p, int start, int end);

void testQuickSort(void);
#endif /* quick_sort_h */
