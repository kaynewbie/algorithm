//
//  binary-search.h
//  algorithm
//
//  Created by Kai on 2019/7/10.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef binary_search_h
#define binary_search_h

#include <stdio.h>
#include "stdbool.h"

/**
 p 指针指向的整型数组长度为 length，数组元素大小递增，用二分法查找其中是否包含 target 元素。
 */
bool binarySearch(int *p, int length, int target);

void testBinarySearch(void);

#endif /* binary_search_h */
