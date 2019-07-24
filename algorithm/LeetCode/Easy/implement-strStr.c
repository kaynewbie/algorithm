//
//  implement-strStr.c
//  algorithm
//
//  Created by Kai on 2019/7/24.
//  Copyright © 2019 kai. All rights reserved.
//

#include "implement-strStr.h"

/*
 https://leetcode.com/problems/implement-strstr/
 */

typedef int (*Handler)(char *, char *);

// MARK:- NOT WORK
/*
 非空判断
 声明两个指针， p1、p2，和一个整型值保存索引 idx
 遍历 haystack，p1 不断往后走，碰到和 needle 第一个字符匹配的元素
 p2 也往后走
 如果一直匹配直到 p2 == '\0'，则成功；在这之前匹配失败，则失败
 
 方法不可行。线性遍历通不过 testStr6 case。
 */
int strStrMethod1(char * haystack, char * needle){
    if (haystack == NULL || needle == NULL) {
        return -1;
    }
    if (*needle == '\0') {
        return 0;
    }
    char *p1, *p2;
    int idx, start;
    
    p1 = haystack;
    p2 = needle;
    idx = 0;
    start = -1;
    while (*p1 != '\0') {
        printf("p1=%c, p2=%c \n", *p1, *p2);
        if (*p1 == *p2) {
            if (start == -1) {
                start = idx;
            }
            ++p2;
        } else {
            if (*p2 == '\0') {
                break;
            } else {
                start = -1;
                p2 = needle;
            }
        }
        ++idx;
        ++p1;
    }
    // 可能存在 needle.length > haystack.length，此时需要判断 *p2 == '\0'
    if (*p2 != '\0') {
        start = -1;
    }
    return start;
}

// MARK:- WORK WELL
int strStrMethod2(char * haystack, char * needle) {
    if (haystack == NULL || needle == NULL) {
        return -1;
    }
    if (*needle == '\0') {
        return 0;
    }
    char *p0, *p1, *p2;
    int idx, start;
    
    p0 = haystack;
    idx = 0;
    start = -1;
    while (*p0 != '\0') {
        p1 = p0;
        p2 = needle;
        start = -1;
        while (*p1 != '\0') {
            if (*p1 == *p2) {
                if (start == -1) {
                    start = idx;
                }
                ++p2;
            } else {
                if (*p2 == '\0') {
                    return start;
                } else {
                    break;
                }
            }
            ++p1;
        }
        if (*p1 == '\0' && *p2 == '\0') {// haystack 和 needle 同时结束
            return start;
        }
        ++idx;
        ++p0;
    }
    return -1;
}

int strStrMethod3(char * haystack, char * needle) {
    int offset = 0;
    char *a, *b;
    
    if (!haystack || !needle) {
        return -1;
    }
    while (1) {
        a = haystack + offset;
        b = needle;
        while (*a != '\0' && *b != '\0' && *a == *b) {
            ++a;
            ++b;
        }
        if (*b == '\0') {
            return offset;
        }
        if (*a == '\0') {
            return -1;
        }
        ++offset;
    }
    
    return -1;
}

/**
 haystack = "hello"
 needle = "ll"
 result = 2
 */
void testStr1(Handler func) {
    char *haystack = "hello";
    char *needle = "ll";
    int result = func(haystack, needle);
    printf("Index of %s in %s is %d\n", needle, haystack, result);
}

/**
 haystack = "aaaaaaaa"
 needle = "bba"
 result = -1
 */
void testStr2(Handler func) {
    char *haystack = "aaaaaaaa";
    char *needle = "bba";
    int result = func(haystack, needle);
    printf("Index of %s in %s is %d\n", needle, haystack, result);
}

/**
 haystack = "qpiwje"
 needle = "iwje"
 result = 2
 */
void testStr3(Handler func) {
    char *haystack = "qpiwje";
    char *needle = "iwje";
    int result = func(haystack, needle);
    printf("Index of %s in %s is %d\n", needle, haystack, result);
}

/**
 haystack = "qpiwje"
 needle = ""
 result = 6
 */
void testStr4(Handler func) {
    char *haystack = "qpiwje";
    char *needle = "";
    int result = func(haystack, needle);
    printf("Index of %s in %s is %d\n", needle, haystack, result);
}

/**
 haystack = "aaa"
 needle = "aaaa"
 result = -1
 */
void testStr5(Handler func) {
    char *haystack = "aaa";
    char *needle = "aaaa";
    int result = func(haystack, needle);
    printf("Index of %s in %s is %d\n", needle, haystack, result);
}

/**
 haystack = "mississippi"
 needle = "issip"
 result = 4
 */
void testStr6(Handler func) {
    char *haystack = "mississippi";
    char *needle = "issip";
    int result = func(haystack, needle);
    printf("Index of %s in %s is %d\n", needle, haystack, result);
}

void testStrMethod1(void) {
    testStr1(strStrMethod1);
    testStr2(strStrMethod1);
    testStr3(strStrMethod1);
    testStr4(strStrMethod1);
    testStr5(strStrMethod1);
    // 测试不通过
    testStr6(strStrMethod1);
}

void testStrMethod2(void) {
    testStr1(strStrMethod2);
    testStr2(strStrMethod2);
    testStr3(strStrMethod2);
    testStr4(strStrMethod2);
    testStr5(strStrMethod2);
    testStr6(strStrMethod2);
}

void testStrMethod3(void) {
    testStr1(strStrMethod3);
    testStr2(strStrMethod3);
    testStr3(strStrMethod3);
    testStr4(strStrMethod3);
    testStr5(strStrMethod3);
    testStr6(strStrMethod3);
}
