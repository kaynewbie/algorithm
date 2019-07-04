/*
 Stack implemented by jiten-thakkar: https://github.com/jiten-thakkar/GenericStack/blob/master/src/lib/stack.c
 */

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include "stdbool.h"

/**
 范型栈
 */
typedef struct s {
    void *data;//实际存储的日志
    int top;//栈顶索引
    int totalElements;//栈内元素数量
    int memberSize;//存储的元素，类型大小
}Stack;

Stack* createStack(int, int);
int stackDestroy(Stack *);
int expandStack(Stack *);
int stackPush(Stack *,  void *);
int stackTop(Stack *,  void *);
int stackPop(Stack *,  void *);
int getMax(Stack *, void *, int (*)(const void *, const void *));

#endif /* stack_h */
