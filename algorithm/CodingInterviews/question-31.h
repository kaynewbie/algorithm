//
//  question-31.h
//  algorithm
//
//  Created by Kai on 2019/8/19.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef question_31_h
#define question_31_h

/*
 给定两个整型数组，第一个数组是栈的入栈顺序，判断第二个数组是栈的一种出栈顺序。
 */

#include <stdio.h>
#include <stdbool.h>

/**
 push 数组是一种入栈序列，判断 pop 数组是否是对应的一种出栈序列

 @param push 入栈顺序排列的数组
 @param pop 栈元素的出栈顺序形成的数组
 @param length 数组长度
 @return 判断是否匹配
 */
bool checkIsPopSequence(int *push, int *pop, int length);

// MARK:- 测试

void testCheckIsPopSequence(void);

#endif /* question_31_h */
