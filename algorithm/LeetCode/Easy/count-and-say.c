//
//  count-and-say.c
//  algorithm
//
//  Created by Kai on 2019/7/25.
//  Copyright © 2019 kai. All rights reserved.
//

#include "count-and-say.h"
#include "stdlib.h"
#include "string.h"

/*
 https://leetcode.com/problems/count-and-say/
 */

/*
 1
 11
 21
 1211
 111221
 312211
 13112221
 1113213211
 */
char * countAndSay(int n){
    char *str = "1";
    if (n < 1) {
        return NULL;
    }
    if (n == 1) {
        return str;
    }
    int idx = 0;
    int countForNum;
    int length = 0;
    char *tmpStr = (char *)malloc(length + 5);
    memset(tmpStr, 0, length + 5);
    
    for (int i = 1; i < n; i++) {
        if (i > 1) {
            tmpStr = calloc(length * 2 + 5, sizeof(char));
        }
        idx = 0;
        length = 0;
        while (str[idx] != '\0') {
            countForNum = 0;
            while (countForNum == 0 || str[idx] == str[countForNum + idx]) {
                countForNum++;
            }
            //此时已经拿到 str[idx] 和 str[idx] 元素数量，写入数组
            tmpStr[length] = countForNum + '0';
            tmpStr[length + 1] = str[idx];
            // 计算当前数组长度
            length += 2;
            idx += countForNum; // 跳过当前连续元素
        }
        str = tmpStr;
    }
    return str;
}

/**
 n = 1
 result = "1";
 */
void testCountAnSay1() {
    int n = 1;
    char *result = countAndSay(n);
    printf("level: %d, result: %s\n", n, result);
}

/**
 n = 2
 result = "11";
 */
void testCountAnSay2() {
    int n = 2;
    char *result = countAndSay(n);
    printf("level: %d, result: %s\n", n, result);
}

/**
 n = 3
 result = "21";
 */
void testCountAnSay3() {
    int n = 3;
    char *result = countAndSay(n);
    printf("level: %d, result: %s\n", n, result);
}

/**
 n = 10
 result = "13211311123113112211";
 */
void testCountAnSay4() {
    int n = 10;
    char *result = countAndSay(n);
    printf("level: %d, result: %s\n", n, result);
}

/**
 n = 13
 */
void testCountAnSay5() {
    int n = 13;
    char *result = countAndSay(n);
    printf("level: %d, result: %s\n", n, result);
}

void testCountAnSay(void) {
    testCountAnSay1();
    testCountAnSay2();
    testCountAnSay3();
    testCountAnSay4();
    testCountAnSay5();
}
