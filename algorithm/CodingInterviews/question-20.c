//
//  question-20.c
//  algorithm
//
//  Created by Kai on 2019/7/21.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-20.h"
#include "stdbool.h"

/*
 检测一个用字符串表示的数值是否正确
 */

bool scanInteger(char **);
bool scanUnsignInteger(char **);

bool isNumeric(char *str) {
    bool isValid;
    
    isValid = scanInteger(&str);
    if (*str == '.') {
        ++str;
        isValid = scanUnsignInteger(&str) || isValid;
    }
    if (*str == 'e' || *str == 'E') {
        ++str;
        isValid = isValid && scanInteger(&str);
    }
    
    return isValid && *str == '\0';
}

/**
 检查整型部分，包含正负符号。
 因为要在函数内部改变传入的指针指向，所以需要 char ** 类型。
 */
bool scanInteger(char **str) {
    if (**str == '+' || **str =='-') {
        ++(*str);
    }
    return scanUnsignInteger(str);
}

/**
 检查不包含符号的整型，比如小数部分。
 */
bool scanUnsignInteger(char **str) {
    const char *before = *str;
    while (**str != '\0' && **str >= '0' && **str <= '9') {
        ++(*str);
    }
    return *str > before;
}

/**
 str = "123.123"
 result = true
 */
void testIsNumeric1() {
    char *str = "123.123";
    bool result = isNumeric(str);
    printf("%s is %s numeric\n", str, result ? "valid" : "not valid");
}

/**
 str = "2.e+2"
 result = true
 */
void testIsNumeric2() {
    char *str = "2.e+2";
    bool result = isNumeric(str);
    printf("%s is %s numeric\n", str, result ? "valid" : "not valid");
}

/**
 str = "123."
 result = true
 */
void testIsNumeric3() {
    char *str = "123.";
    bool result = isNumeric(str);
    printf("%s is %s numeric\n", str, result ? "valid" : "not valid");
}

/**
 str = "0.123"
 result = true
 */
void testIsNumeric4() {
    char *str = "0.123";
    bool result = isNumeric(str);
    printf("%s is %s numeric\n", str, result ? "valid" : "not valid");
}

/**
 str = "123"
 result = true
 */
void testIsNumeric5() {
    char *str = "123";
    bool result = isNumeric(str);
    printf("%s is %s numeric\n", str, result ? "valid" : "not valid");
}

/**
 str = ".123"
 result = true
 */
void testIsNumeric6() {
    char *str = ".123";
    bool result = isNumeric(str);
    printf("%s is %s numeric\n", str, result ? "valid" : "not valid");
}

/**
 str = "+12354.123"
 result = true
 */
void testIsNumeric7() {
    char *str = "+12354.123";
    bool result = isNumeric(str);
    printf("%s is %s numeric\n", str, result ? "valid" : "not valid");
}

/**
 str = "-12354.123"
 result = true
 */
void testIsNumeric8() {
    char *str = "-12354.123";
    bool result = isNumeric(str);
    printf("%s is %s numeric\n", str, result ? "valid" : "not valid");
}

/**
 str = "-12354.123e"
 result = true
 */
void testIsNumeric9() {
    char *str = "-12354.123e";
    bool result = isNumeric(str);
    printf("%s is %s numeric\n", str, result ? "valid" : "not valid");
}

/**
 str = "-12354.123E-3"
 result = true
 */
void testIsNumeric10() {
    char *str = "-12354.123E-3";
    bool result = isNumeric(str);
    printf("%s is %s numeric\n", str, result ? "valid" : "not valid");
}

/**
 str = "-12354.123e-3"
 result = true
 */
void testIsNumeric11() {
    char *str = "-12354.123e-3";
    bool result = isNumeric(str);
    printf("%s is %s numeric\n", str, result ? "valid" : "not valid");
}

/**
 str = ".e+2"
 result = false
 */
void testIsNumeric12() {
    char *str = ".e+2";
    bool result = isNumeric(str);
    printf("%s is %s numeric\n", str, result ? "valid" : "not valid");
}

/**
 str = "0.123.123"
 result = false
 */
void testIsNumeric13() {
    char *str = "0.123.123";
    bool result = isNumeric(str);
    printf("%s is %s numeric\n", str, result ? "valid" : "not valid");
}

/**
 str = "0.123e"
 result = false
 */
void testIsNumeric14() {
    char *str = "0.123e";
    bool result = isNumeric(str);
    printf("%s is %s numeric\n", str, result ? "valid" : "not valid");
}

void testIsNumeric(void) {
    testIsNumeric1();
    testIsNumeric2();
    testIsNumeric3();
    testIsNumeric4();
    testIsNumeric5();
    testIsNumeric6();
    testIsNumeric7();
    testIsNumeric8();
    testIsNumeric9();
    testIsNumeric10();
    testIsNumeric11();
    testIsNumeric12();
    testIsNumeric13();
    testIsNumeric14();
}
