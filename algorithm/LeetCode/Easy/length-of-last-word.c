//
//  length-of-last-word.c
//  algorithm
//
//  Created by Kai on 2019/7/27.
//  Copyright © 2019 kai. All rights reserved.
//

#include "length-of-last-word.h"
#include "string.h"
/*
 https://leetcode.com/problems/length-of-last-word/
 */

/*
 获取字符串长度
 反向遍历，找到第一个非空格开头的，直到下一个空格，记录长度
 */
int lengthOfLastWord(char * s) {
    int length, lastWordLength;
    
    lastWordLength = 0;
    length = (int)strlen(s);
    for (int i = length - 1; i >= 0; i--) {
        if (s[i] == ' ' && lastWordLength != 0) {
            return lastWordLength;
        }
        if (s[i] != ' ') {
            lastWordLength++;
        }
    }
    return lastWordLength;
}

/*
 s = "hello world"
 result = 5
 */
void testLengthOfLastWord1() {
    char *s = "hello world";
    int result = lengthOfLastWord(s);
    printf("length of last word in %s is %d\n", s, result);
}

/*
 s = " "
 result = 0
 */
void testLengthOfLastWord2() {
    char *s = " ";
    int result = lengthOfLastWord(s);
    printf("length of last word in %s is %d\n", s, result);
}

/*
 s = "length of last word"
 result = 4
 */
void testLengthOfLastWord3() {
    char *s = "length of last word";
    int result = lengthOfLastWord(s);
    printf("length of last word in %s is %d\n", s, result);
}

/*
 s = "length of last w"
 result = 1
 */
void testLengthOfLastWord4() {
    char *s = "length of last w";
    int result = lengthOfLastWord(s);
    printf("length of last word in %s is %d\n", s, result);
}

/*
 s = "length of last w  "
 result = 1
 */
void testLengthOfLastWord5() {
    char *s = "length of last w";
    int result = lengthOfLastWord(s);
    printf("length of last word in %s is %d\n", s, result);
}

void testLengthOfLastWord(void) {
    testLengthOfLastWord1();
    testLengthOfLastWord2();
    testLengthOfLastWord3();
    testLengthOfLastWord4();
    testLengthOfLastWord5();
}
