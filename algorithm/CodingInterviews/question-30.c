//
//  question-30.c
//  algorithm
//
//  Created by Kai on 2019/8/19.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-30.h"
#include <stdlib.h>

#define MIN(x, y) ((x < y) ? x : y)

/**
 创建栈结构
 */
StackWithMin *createStackWithMin(void) {
    StackWithMin *s;
    Stack *main, *minValues;
    
    s = malloc(sizeof(StackWithMin));
    main = createStack(sizeof(int), 10);
    minValues = createStack(sizeof(int), 10);
    s->main = main;
    s->minValues = minValues;
    
    return s;
}

/**
 压栈操作
 
 @param StackWithMin 栈
 @param void * 数据源地址
 @return 0成功，否则不成功
 */
int stackPushWithMin(StackWithMin *s,  int *src) {
    int min;
    int pushToMain, pushToMin;
    
    pushToMain = stackPush(s->main, src);
    
    min = 0;
    stackTop(s->minValues, &min);
    min = MIN(min, *src);
    pushToMin = stackPush(s->minValues, &min);
    
    return pushToMain & pushToMin;
}

/**
 出栈操作
 
 @param StackWithMin 栈
 @param void * 新数据地址
 @return 0成功，否则不成功
 */
int stackPopWithMin(StackWithMin *s,  int *dst) {
    int min;
    int popFromMain, popFromMin;
    
    min = 0;
    popFromMain = stackPop(s->main, dst);
    popFromMin = stackPop(s->minValues, &min);
    
    return popFromMain & popFromMin;
}

/**
 栈中最小值
 
 @param StackWithMin 栈
 @param void * 新数据地址
 @return 0成功，否则不成功
 */
int minInStack(StackWithMin *s, int *dst) {
    int result;
    
    result = stackTop(s->minValues, dst);
    
    return result;
}
