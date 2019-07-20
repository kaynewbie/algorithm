//
//  question-19.c
//  algorithm
//
//  Created by Kai on 2019/7/20.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-19.h"
#include "stdbool.h"

/*
 匹配正则表达式
 */

bool match(char *str, char *pattern) {
    if (*str == '\0' && *pattern == '\0') {
        return true;
    }
    if (*str != '\0' && *pattern == '\0') {
        return false;
    }
    if (*(pattern + 1) == '*') {
        if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
            return match(str + 1, pattern + 2) ||
            match(str + 1, pattern) ||
            match(str, pattern + 2);
        } else {
            return match(str, pattern + 2);
        }
    }
    if (*str == *pattern || (*pattern == '.' && *str != '\0')) {
        return match(str + 1, pattern + 1);
    }
    return false;
}

/**
 str = "aaa"
 pattern = "a*"
 result = true
 */
void testMatch1() {
    char *str = "aaa";
    char *pattern = "a*";
    bool result = match(str, pattern);
    printf("%s evaluate %s result is %s\n", str, pattern, result ? "true" : "false");
}

/**
 str = "aab"
 pattern = "a*b"
 result = true
 */
void testMatch2() {
    char *str = "aab";
    char *pattern = "a*b";
    bool result = match(str, pattern);
    printf("%s evaluate %s result is %s\n", str, pattern, result ? "true" : "false");
}

/**
 str = "aab"
 pattern = "a.b"
 result = true
 */
void testMatch3() {
    char *str = "aab";
    char *pattern = "a.b";
    bool result = match(str, pattern);
    printf("%s evaluate %s result is %s\n", str, pattern, result ? "true" : "false");
}

/**
 str = "ab"
 pattern = "a.*b"
 result = true
 */
void testMatch4() {
    char *str = "ab";
    char *pattern = "a.*b";
    bool result = match(str, pattern);
    printf("%s evaluate %s result is %s\n", str, pattern, result ? "true" : "false");
}

/**
 str = "aiqowjefpijqwpfb"
 pattern = "a.*b"
 result = true
 */
void testMatch5() {
    char *str = "aiqowjefpijqwpfb";
    char *pattern = "a.*b";
    bool result = match(str, pattern);
    printf("%s evaluate %s result is %s\n", str, pattern, result ? "true" : "false");
}

/**
 str = "aiqowjefpijqwpfb"
 pattern = "a.b"
 result = false
 */
void testMatch6() {
    char *str = "aiqowjefpijqwpfb";
    char *pattern = "a.b";
    bool result = match(str, pattern);
    printf("%s evaluate %s result is %s\n", str, pattern, result ? "true" : "false");
}

/**
 str = "a"
 pattern = "a*a"
 result = true
 */
void testMatch7() {
    char *str = "a";
    char *pattern = "a*a";
    bool result = match(str, pattern);
    printf("%s evaluate %s result is %s\n", str, pattern, result ? "true" : "false");
}

/**
 str = ""
 pattern = "a*"
 result = true
 */
void testMatch8() {
    char *str = "";
    char *pattern = "a*";
    bool result = match(str, pattern);
    printf("%s evaluate %s result is %s\n", str, pattern, result ? "true" : "false");
}

/**
 str = ""
 pattern = ".*"
 result = true
 */
void testMatch9() {
    char *str = "";
    char *pattern = ".*";
    bool result = match(str, pattern);
    printf("%s evaluate %s result is %s\n", str, pattern, result ? "true" : "false");
}

void testMatch(void) {
    testMatch1();
    testMatch2();
    testMatch3();
    testMatch4();
    testMatch5();
    testMatch6();
    testMatch7();
    testMatch8();
    testMatch9();
}
