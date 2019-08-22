//
//  array-step-through.h
//  algorithm
//
//  Created by Kai on 2019/8/22.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef array_step_through_h
#define array_step_through_h

/*
 数组序列，每个元素的值表示最多可以向后跳多远，计算最少跳多少次可以到达末尾。
 */

#include <stdio.h>

int arrayStepThrough(int *array, int len);

// MARK:- 测试
void testArrayStepThrough(void);

#endif /* array_step_through_h */
