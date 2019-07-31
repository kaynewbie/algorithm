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
        step = (right - 1 - i) * 2 + 1;
        if (step > resultLength) {
            resultLength = step;
            resultStart = left + 1;
        }
    }
    
    printf("start=%d, length=%d\n", resultStart, resultLength);
    if (resultLength > 0) {
        char *str = malloc(sizeof(char) * (resultLength + 1));
        memcpy(str, p + resultStart, sizeof(char) * resultLength);
        *(str + resultLength) = '\0';
        return str;
    }
    return NULL;
}

/*
 cbbd -> bb
 babad -> bab
 */
void testLongestPalindromicSubstring() {
    char *str = "cbbd";
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

/*
 参考：https://segmentfault.com/a/1190000002991199#articleHeader14
 */

//MARK:- 方法二、Manacher 算法

/**
 格式化原字符串，如，aaba -> $#a#a#b#a#^
 */
char *formatString(char s[], int length) {
    int l = length * 2 + 3;
    char *tmp = malloc(sizeof(char) * l);
    
    tmp[0] = '$';
    tmp[l - 1] = '^';
    for (int i = 0; i < length; i++) {
        tmp[i * 2 + 1] = '#';
        tmp[i * 2 + 2] = s[i];
    }
    tmp[l - 2] = '#';
    
//    printf("new string:\n");
//    for (int i = 0; i < l; i++) {
//        printf("%c\n", *(tmp + i));
//    }
    
    return tmp;
}

char *longestPalindromicSubstringByManacher(char *s, int length) {
    char *newStr = formatString(s, length);
    int newLength = length * 2 + 3;
    
    int p[newLength];
    memset(p, 0, sizeof(int) * newLength);
    
    int mx = 0, id = 0;
    int tmp;
    for (int i = 1; i < newLength - 1; i++) {
        tmp = p[2 * id - i] > mx - i ? mx - i : p[2 * id - i];
        p[i] = mx > i ? tmp : 1;
        while (*(newStr + (i + p[i])) == *(newStr + (i - p[i]))) {
            p[i]++;
        }
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
    }
    
    int max = 0, index = 0;
    for (int i = 1; i < newLength - 1; i++) {
        if (p[i] > max) {
            max = p[i];
            index = i;
        }
    }
    
    char *str = malloc(sizeof(char) * max);
    int start = (index - max) / 2;
    memcpy(str, s + start, sizeof(char) * (max - 1));
    *(str + max - 1) = '\0';
    return str;
}

void testLongestPalindromicSubstringByManacher(void) {
    char *str = "abbd";
    int length = 0;
    char *tmp = str;
    while (*(tmp++) != '\0') {
        length++;
    }
    
    printf("result:\n");
    char *result = longestPalindromicSubstringByManacher(str, length);
    
    char *p = result;
    while (p != NULL && *p != '\0') {
        printf("%c\n", *(p++));
    }
    printf("Done\n");
}
