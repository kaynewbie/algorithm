//
//  longest-palindromic-substring.c
//  algorithm
//
//  Created by Kai on 2019/7/12.
//  Copyright © 2019 kai. All rights reserved.
//

#include "longest-palindromic-substring.h"
#include "string.h"
#include "stdlib.h"

/*
 参考链接：
 https://www.cnblogs.com/TenosDoIt/p/3675788.html
 */

/*
 最长的轴对称子字符串（回文）。
 如，abbaabba，结果为: abba。
 */

//MARK:- 方法一、遍历字符串，采用中间往两边延伸的方式寻找回文字符串

/**
 时间复杂度：O(n)，空间复杂度：O(1)
 */
char *longestPalindromicSubstring(char *p, int length) {
    int left;
    int right;
    int step;
    int resultLength;//最长回文字符串的长度
    int resultStart;//最长回文字符串的起始索引
    
    resultLength = 0;
    resultStart = -1;
    //回文字符串长度为偶数
    for (int i = 1; i < length; i++) {
        left = i - 1;
        right = i;
        while (left >= 0 && right < length && *(p + left) == *(p + right)) {
            left--;
            right++;
        }
        step = right - i;
        if (step * 2 > resultLength) {
            resultLength = step * 2;
            resultStart = left + 1;
        }
    }
    //回文字符串长度为奇数
    for (int i = 1; i < length - 1; i++) {
        left = i - 1;
        right = i + 1;
        while (left >= 0 && right < length && *(p + left) == *(p + right)) {
            left--;
            right++;
        }
        step = right - 1 - i;
        if (step * 2 > resultLength) {
            resultLength = step * 2;
            resultStart = left + 1;
        }
    }
    
    if (resultLength > 0) {
        char *str = malloc(sizeof(char) * (resultLength + 1));
        memcpy(str, p + resultStart, sizeof(char) * resultLength);
        *(str + resultLength) = '\0';
        return str;
    }
    return NULL;
}

void testLongestPalindromicSubstring() {
    char *str = "babad";
    int length = 0;
    char *tmp = str;
    while (*(tmp++) != '\0') {
        length++;
    }
    
    printf("str length=%d\n", length);
    char *result = longestPalindromicSubstring(str, length);
    
    char *p = result;
    while (p != NULL && *p != '\0') {
        printf("%c\n", *(p++));
    }
    printf("Done\n");
}
