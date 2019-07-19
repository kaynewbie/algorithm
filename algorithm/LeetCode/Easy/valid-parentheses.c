//
//  valid-parentheses.c
//  algorithm
//
//  Created by Kai on 2019/7/19.
//  Copyright © 2019 kai. All rights reserved.
//

#include "valid-parentheses.h"
#include "stdbool.h"

/*
 https://leetcode.com/problems/valid-parentheses/
 */

int isValidCore(char *s, int idx) {
    if (*(s + idx) == '\0') {
        return 0;
    }
    char current = *(s + idx);
    int matchedIdx = 0;
    if (current == '(' || current == '[' || current == '{') {
        matchedIdx = isValidCore(s, idx + 1);
        
        if (matchedIdx == 0 || matchedIdx == -1) {
            return -1;
        }
        char matchPattern;
        switch (*(s + idx)) {
            case '(':
                matchPattern = ')';
                break;
            case '[':
                matchPattern = ']';
                break;
            case '{':
                matchPattern = '}';
                break;
            default:
                return -1;
        }
        if (*(s + matchedIdx) == matchPattern) {
            return isValidCore(s, matchedIdx + 1);
        } else {
            return -1;
        }
    } else {
        return idx == 0 ? -1 : idx;
    }
}

/**
 借助 栈/递归 实现，时间复杂度：O(n)，空间复杂度：O(n)
 */
bool isValid(char * s){
    int result = isValidCore(s, 0);
    if (result == 0) {
        return true;
    } else {
        return false;
    }
}

/**
 s = "()()"
 */
void testIsValid1(void) {
    char *s = "()()";
    bool result = isValid(s);
    printf("%s is %s\n", s, result ? "valid" : "not valid");
}

/**
 s = "({[]})"
 */
void testIsValid2(void) {
    char *s = "({[]})";
    bool result = isValid(s);
    printf("%s is %s\n", s, result ? "valid" : "not valid");
}

/**
 s = "((({[]})))"
 */
void testIsValid3(void) {
    char *s = "((({[]})))";
    bool result = isValid(s);
    printf("%s is %s\n", s, result ? "valid" : "not valid");
}

/**
 s = ""
 */
void testIsValid4(void) {
    char *s = "";
    bool result = isValid(s);
    printf("%s is %s\n", s, result ? "valid" : "not valid");
}

/**
 s = "((((((()))))))"
 */
void testIsValid5(void) {
    char *s = "((((((()))))))";
    bool result = isValid(s);
    printf("%s is %s\n", s, result ? "valid" : "not valid");
}

/**
 s = "({[)"
 */
void testIsValid6(void) {
    char *s = "({[)";
    bool result = isValid(s);
    printf("%s is %s\n", s, result ? "valid" : "not valid");
}

/**
 s = "]})"
 */
void testIsValid7(void) {
    char *s = "]})";
    bool result = isValid(s);
    printf("%s is %s\n", s, result ? "valid" : "not valid");
}

/**
 s = "()[]{}"
 */
void testIsValid8(void) {
    char *s = "()[]{}";
    bool result = isValid(s);
    printf("%s is %s\n", s, result ? "valid" : "not valid");
}

/**
 s = "(]"
 */
void testIsValid9(void) {
    char *s = "(]";
    bool result = isValid(s);
    printf("%s is %s\n", s, result ? "valid" : "not valid");
}

/**
 s = "("
 */
void testIsValid10(void) {
    char *s = "(";
    bool result = isValid(s);
    printf("%s is %s\n", s, result ? "valid" : "not valid");
}

/**
 s = "[])"
 */
void testIsValid11(void) {
    char *s = "[])";
    bool result = isValid(s);
    printf("%s is %s\n", s, result ? "valid" : "not valid");
}

void testIsValid(void) {
    testIsValid1();
    testIsValid2();
    testIsValid3();
    testIsValid4();
    testIsValid5();
    testIsValid6();
    testIsValid7();
    testIsValid8();
    testIsValid9();
    testIsValid10();
    testIsValid11();
}
