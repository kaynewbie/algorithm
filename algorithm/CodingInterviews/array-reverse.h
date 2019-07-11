//
//  array-reverse.h
//  algorithm
//
//  Created by Kai on 2019/7/11.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef array_reverse_h
#define array_reverse_h

#include <stdio.h>

/*
 递增排序数组，前m位平移到数组末尾，相当于变成了两个递增数组。在此数组中查找 target。
 */
int reversedArray(int p[], int length, int target);

void testreversedArray1(void);
void testreversedArray2(void);

#endif /* array_reverse_h */
