//
//  question-30.h
//  algorithm
//
//  Created by Kai on 2019/8/19.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef question_30_h
#define question_30_h

/*
 设计一个栈，有 min 函数。该栈中，调用 min, push, pop 时间复杂度都是 O(1)。
 */

#include <stdio.h>
#include "stack.h"

// 该结构内部用两个栈实现，main 栈用于存储目标数据，minValues 存储最小值。
typedef struct StackWithMin {
    Stack *main;
    Stack *minValues;
}StackWithMin;


/**
 创建栈结构
 */
StackWithMin *createStackWithMin(void);

/**
 压栈操作

 @param StackWithMin 栈
 @param void * 数据源地址
 @return 0成功，否则不成功
 */
int stackPushWithMin(StackWithMin *,  int *);

/**
 出栈操作

 @param StackWithMin 栈
 @param void * 新数据地址
 @return 0成功，否则不成功
 */
int stackPopWithMin(StackWithMin *,  int *);

/**
 栈中最小值

 @param StackWithMin 栈
 @param void * 新数据地址
 @return 0成功，否则不成功
 */
int minInStack(StackWithMin *, int *);

#endif /* question_30_h */
