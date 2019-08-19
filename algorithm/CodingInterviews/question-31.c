//
//  question-31.c
//  algorithm
//
//  Created by Kai on 2019/8/19.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-31.h"
#include "stack.h"

/*
 建立辅助栈，
 */

bool checkIsPopSequence(int *push, int *pop, int length) {
    if (push == NULL || pop == NULL || length <= 0) {
        return false;
    }
    
    Stack *stack;
    int topValue;
    int *pNextPush = push;
    int *pNextPop = pop;

    topValue = 0;
    stack = createStack(sizeof(int), length);
    
    /*
     遍历 pop 数组，然后用当前遍历到的元素(*pNextPop)在 push 数组中进行压栈操作：push 中，在 *pNextPop 前面的元素都要压栈，
     批量压栈操作完成后，如果能找到 *pNextPop，则弹出元素，pNextPop 后移，继续循环；否则，终止循环
     */
    while (pNextPop - pop < length) {// 必须全部弹出 pop 中的元素才是成功
        stackTop(stack, &topValue);
        while (stack->top < 0 || topValue != *pNextPop) {
            if (pNextPush - push == length) {
                break;
            }
            stackPush(stack, pNextPush);
            topValue = *pNextPush;
            pNextPush++;
        }
        stackTop(stack, &topValue);
        if (topValue != *pNextPop) {
            break;
        }
        stackPop(stack, &topValue);
        pNextPop++;
    }
    // 循环终止时，栈内的情况
    if (stack->top < 0 && pNextPop - pop == length)
        return true;
    
    return false;
}

// MARK:- 测试

void testCheckIsPopSequence1(void) {
    const int length = 5;
    int push[length] = {1, 2, 3, 4, 5};
    int pop[length] = {5, 4, 3, 2, 1};
    bool result = checkIsPopSequence(push, pop, length);
    printf("%s: %s\n", __func__, result ? "true" : "false");
}

void testCheckIsPopSequence2(void) {
    const int length = 5;
    int push[length] = {1, 2, 3, 4, 5};
    int pop[length] = {4, 5, 3, 2, 1};
    bool result = checkIsPopSequence(push, pop, length);
    printf("%s: %s\n", __func__, result ? "true" : "false");
}

void testCheckIsPopSequence3(void) {
    const int length = 5;
    int push[length] = {1, 2, 3, 4, 5};
    int pop[length] = {4, 3, 5, 2, 1};
    bool result = checkIsPopSequence(push, pop, length);
    printf("%s: %s\n", __func__, result ? "true" : "false");
}

void testCheckIsPopSequence4(void) {
    const int length = 5;
    int push[length] = {1, 2, 3, 4, 5};
    int pop[length] = {1, 2, 3, 4, 5};
    bool result = checkIsPopSequence(push, pop, length);
    printf("%s: %s\n", __func__, result ? "true" : "false");
}

void testCheckIsPopSequence5(void) {
    const int length = 5;
    int push[length] = {1, 2, 3, 4, 5};
    int pop[length] = {3, 2, 1, 4, 5};
    bool result = checkIsPopSequence(push, pop, length);
    printf("%s: %s\n", __func__, result ? "true" : "false");
}

void testCheckIsPopSequence6(void) {
    const int length = 5;
    int push[length] = {1, 2, 3, 4, 5};
    int pop[length] = {5, 5, 3, 2, 1};
    bool result = checkIsPopSequence(push, pop, length);
    printf("%s: %s\n", __func__, result ? "true" : "false");
}

void testCheckIsPopSequence7(void) {
    const int length = 5;
    int push[length] = {1, 2, 3, 4, 5};
    int pop[length] = {5, 4, 2, 3, 1};
    bool result = checkIsPopSequence(push, pop, length);
    printf("%s: %s\n", __func__, result ? "true" : "false");
}

void testCheckIsPopSequence(void) {
    testCheckIsPopSequence1();
    testCheckIsPopSequence2();
    testCheckIsPopSequence3();
    testCheckIsPopSequence4();
    testCheckIsPopSequence5();
    testCheckIsPopSequence6();
    testCheckIsPopSequence7();
}
