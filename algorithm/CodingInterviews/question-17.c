//
//  question-17.c
//  algorithm
//
//  Created by Kai on 2019/7/19.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-17.h"
#include "stdbool.h"
#include "stdlib.h"
#include "string.h"

bool increment(char *num);
void printNumIn(char *num);

void print1ToMaxOfN(int n) {
    if (n <= 0) {
        return;
    }
    char *num = malloc(n + 1);
    num[n] = '\0';
    memset(num, '0', n);
    
    while (!increment(num)) {
        printNumIn(num);
    }
}

int lengthOf(char *str) {
    int length = 0;
    while (*(str + length) != '\0') {
        length++;
    }
    return length;
}

bool increment(char *num) {
    int length = lengthOf(num);
    
    int nTakeOver = 0;
    int sum;
    
    for (int i = length - 1; i >= 0; i--) {
        sum = num[i] - '0' + nTakeOver;
        nTakeOver = 0;
        if (i == length - 1) {
            sum++;
        }
        if (sum >= 10) {
            if (i == 0) {
                return true;
            } else {
                sum -= 10;
                nTakeOver = 1;
                num[i] = '0' + sum;
            }
        } else {
            num[i] = sum + '0';
            break;
        }
    }
    return false;
}

void printNumIn(char *num) {
    bool start0 = true;
    while (*num != '\0') {
        if (start0 && *num != '0') {
            start0 = false;
        }
        if (!start0) {
            printf("%c", *num);
        }
        num++;
    }
    printf("\n");
}

/**
 num = "10"
 */
void testIncrement1(void) {
    int length = 2;
    char *num = malloc(sizeof(char) * (length + 1));
    memcpy(num, "10", length);
    num[length] = '\0';
    
    printf("before increment is %s\n", num);
    bool overflow = increment(num);
    if (overflow) {
        printf("increment overflow\n");
    } else {
        printf("after increment is %s\n", num);
    }
    printf("-----------------\n");
}

/**
 num = "0"
 */
void testIncrement2(void) {
    int length = 1;
    char *num = malloc(sizeof(char) * (length + 1));
    memcpy(num, "0", length);
    num[length] = '\0';
    
    printf("before increment is %s\n", num);
    bool overflow = increment(num);
    if (overflow) {
        printf("increment overflow\n");
    } else {
        printf("after increment is %s\n", num);
    }
    printf("-----------------\n");
}

/**
 num = "99"
 */
void testIncrement3(void) {
    int length = 2;
    char *num = malloc(sizeof(char) * (length + 1));
    memcpy(num, "99", length);
    num[length] = '\0';
    
    printf("before increment is %s\n", num);
    bool overflow = increment(num);
    if (overflow) {
        printf("increment overflow\n");
    } else {
        printf("after increment is %s\n", num);
    }
    printf("-----------------\n");
}

/**
 num = "999"
 */
void testIncrement4(void) {
    int length = 3;
    char *num = malloc(sizeof(char) * (length + 1));
    memcpy(num, "999", length);
    num[length] = '\0';
    
    printf("before increment is %s\n", num);
    bool overflow = increment(num);
    if (overflow) {
        printf("increment overflow\n");
    } else {
        printf("after increment is %s\n", num);
    }
    printf("-----------------\n");
}

/**
 num = "1234"
 */
void testIncrement5(void) {
    int length = 4;
    char *num = malloc(sizeof(char) * (length + 1));
    memcpy(num, "1234", length);
    num[length] = '\0';
    
    printf("before increment is %s\n", num);
    bool overflow = increment(num);
    if (overflow) {
        printf("increment overflow\n");
    } else {
        printf("after increment is %s\n", num);
    }
    printf("-----------------\n");
}

/**
 num = "1999"
 */
void testIncrement6(void) {
    int length = 4;
    char *num = malloc(sizeof(char) * (length + 1));
    memcpy(num, "1999", length);
    num[length] = '\0';
    
    printf("before increment is %s\n", num);
    bool overflow = increment(num);
    if (overflow) {
        printf("increment overflow\n");
    } else {
        printf("after increment is %s\n", num);
    }
    printf("-----------------\n");
}

void testPrint1ToMaxOfN(void) {
    print1ToMaxOfN(3);
}

void testIncrement(void) {
    testIncrement1();
    testIncrement2();
    testIncrement3();
    testIncrement4();
    testIncrement5();
    testIncrement6();
}
