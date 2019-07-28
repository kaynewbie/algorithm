//
//  add-binary.c
//  algorithm
//
//  Created by Kai on 2019/7/28.
//  Copyright © 2019 kai. All rights reserved.
//

#include "add-binary.h"
#include "string.h"
#include "stdlib.h"

#define MAX(x, y) (( x > y) ? x : y)

char * addBinary(char * a, char * b){
    int lengthA = (int)strlen(a);
    int lengthB = (int)strlen(b);
    int idxA = lengthA - 1, idxB = lengthB - 1;
    
    // 多开辟两个字节，一个用于存 '\0'，一个用于可能的进位
    int resultL = MAX(lengthA, lengthB) + 2;
    char *result = calloc(resultL, sizeof(char));
    result[resultL - 1] = '\0';

    int diff = 0;
    int idxInResult = resultL - 2;
    int currentA, currentB, sum;
    while (1) {
        if (idxA < 0 && idxB < 0 && diff == 0) {
            break;
        }
        if (idxA >= 0) {
            currentA = a[idxA] - '0';
            idxA--;
        } else {
            currentA = 0;
        }
        if (idxB >= 0) {
            currentB = b[idxB] - '0';
            idxB--;
        } else {
            currentB = 0;
        }
        
        sum = currentA + currentB + diff;
        if (sum >= 2) {
            result[idxInResult] = sum - 2 + '0';
            diff = 1;
        } else {
            result[idxInResult] = sum + '0';
            diff = 0;
        }
        idxInResult--;
    }
     // idxInResult 最后可能是 0 或 -1：0，表示最高位不需要进一位，是多余的；-1 表示最高位进了一位
    return idxInResult == 0 ? result + 1 : result;
}

/*
 a = "11"
 b = "1"
 */
void testAddBinary1(void) {
    char *a = "11";
    char *b = "1";
    char *c = addBinary(a, b);
    printf("Add binary: %s + %s = %s\n", a, b, c);
}

/*
 a = "111"
 b = "11"
 */
void testAddBinary2(void) {
    char *a = "111";
    char *b = "11";
    char *c = addBinary(a, b);
    printf("Add binary: %s + %s = %s\n", a, b, c);
}

/*
 a = "0"
 b = "11"
 */
void testAddBinary3(void) {
    char *a = "0";
    char *b = "11";
    char *c = addBinary(a, b);
    printf("Add binary: %s + %s = %s\n", a, b, c);
}

void testAddBinary(void) {
    testAddBinary1();
    testAddBinary2();
    testAddBinary3();
}
