//
//  longest-common-prefix.c
//  algorithm
//
//  Created by Kai on 2019/7/17.
//  Copyright © 2019 kai. All rights reserved.
//

#include "longest-common-prefix.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

/*
 https://leetcode.com/problems/longest-common-prefix/
 
 Write a function to find the longest common prefix string amongst an array of strings.
 If there is no common prefix, return an empty string "".
 */

typedef char *(*LongestCommonPrefixFunc)(char **, int);

// MARK:- 方法一
char *longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize <= 0) {
        return "";
    }
    int capacity = 5;
    char *pInFirstStr = *strs;
//    char *result = malloc(sizeof(char) * capacity);
    char *result = calloc(capacity, sizeof(char));
    int idx = 0;
    
    int i;
    char c;
    bool success;
    while (*(pInFirstStr + idx) != '\0') {
        success = true;
        for (i = 1; i < strsSize; i++) {
            c = *(*(strs + i) + idx); // 可能直接超出数组范围，操作不可知内存有风险
            if (*(pInFirstStr + idx) != c) {
                success = false;
                break;
            }
        }
        if (!success) {
            break;
        }
        if (idx >= capacity) {//extent
            capacity += 10;
            result = (char *)realloc(result, capacity); // 多次 realloc 性能低，更好的做法是获取前缀长度，然后从第一个字符串中拷贝出来。
        }
        *(result + idx) = *(pInFirstStr + idx);
        idx++;
    }
    return result;
}

// MARK:- 方法二
int commonPrefixLength(char *first, int firstL, char *second);

/**
 1. 声明最长共同前缀指针，起始指向第一个字符串
 2. 声明最长共同前缀长度
 3. 遍历
 4. 遍历结束后，从第一个字符串中拷贝出指定长度的字符串
 */
char *longestCommonPrefix2(char ** strs, int strsSize){
    if (strsSize <= 0) {
        return NULL;
    }
    char *firstStr; // 第一个字符串
    char *currentS; // 遍历过程中的当前字符串
    int prefixLength; // 遍历过程中的最长公共前缀长度
    
    firstStr = *strs;
    prefixLength = (int)strlen(firstStr);
    
    for (int i = 1; i < strsSize; i++) {
        currentS = strs[i];
        
        prefixLength = commonPrefixLength(firstStr, prefixLength, currentS);
        if (prefixLength == 0) {
            break;
        }
    }
    char *result = malloc((sizeof(char) * prefixLength) + 1);
    memcpy(result, firstStr, prefixLength);
    result[prefixLength] = '\0';
    return result;
}

/**
 获取两个字符串最大前缀长度
 */
int commonPrefixLength(char *first, int firstL, char *second) {
    int commonL = 0;
    while (commonL < firstL && *first != '\0' && first[commonL] == second[commonL]) {
        commonL++;
    }
    return commonL;
}

// MARK:- 测试
/*
 array: [""]
 prefix: ""
 */
void testLongestCommonPrefix1(LongestCommonPrefixFunc func) {
    char *strs[0] = {};
    char *prefix = func(strs, 0);
    printf("prefix: %s\n", prefix);
}

/*
 array: ["flow", "flower", "flat"]
 prefix: "fl"
 */
void testLongestCommonPrefix2(LongestCommonPrefixFunc func) {
    char *strs[3] = {"flow", "flower", "flat"};
    char *prefix = func(strs, 3);
    printf("prefix: %s\n", prefix);
}

/*
 array: ["flower","flow","flight"]
 prefix: "fl"
 */
void testLongestCommonPrefix3(LongestCommonPrefixFunc func) {
    char *strs[3] = {"flower","flow","flight"};
    char *prefix = func(strs, 3);
    printf("prefix: %s\n", prefix);
}

/*
 array: ["king", "kid", "done"]
 prefix: ""
 */
void testLongestCommonPrefix4(LongestCommonPrefixFunc func) {
    char *strs[4] = {"king", "kid", "kitty", "keyboard"};
    char *prefix = func(strs, 4);
    printf("prefix: %s\n", prefix);
}

void testLongestCommonPrefix5(LongestCommonPrefixFunc func) {
    int length = 20;
    char *strs[length];
    for (int i = 0; i < length; i++) {
        char *str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        strs[i] = str;
    }
    char *prefix = func(strs, length);
    printf("prefix: %s\n", prefix);
}

/*
 array: ["king", "test", "done"]
 prefix: ""
 */
void testLongestCommonPrefix6(LongestCommonPrefixFunc func) {
    char *strs[3] = {"king", "test", "done"};
    char *prefix = func(strs, 3);
    printf("prefix: %s\n", prefix);
}

void testLongestCommonPrefix(void) {
//    testLongestCommonPrefix1(longestCommonPrefix2);
//    testLongestCommonPrefix2(longestCommonPrefix2);
//    testLongestCommonPrefix3(longestCommonPrefix2);
//    testLongestCommonPrefix4(longestCommonPrefix2);
//    testLongestCommonPrefix5(longestCommonPrefix2);
    testLongestCommonPrefix6(longestCommonPrefix2);
    printf("=====%d\n", '\0');
}
