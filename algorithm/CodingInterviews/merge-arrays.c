//
//  merge-arrays.c
//  algorithm
//
//  Created by Kai on 2019/7/3.
//  Copyright © 2019 kai. All rights reserved.
//

#include "merge-arrays.h"
#include "string.h"
#include "stdlib.h"

/*
 URL Encode：字符串中的空格替换成 %20
 分析：连续内存中插入元素，会导致后续元素后移，这种情况考虑，从后往前插入。
 */
char *replaceWhiteSpace(char text[], unsigned long length) {
    if (text == NULL) {
        return text;
    }
    char *p;
    int count;
    
    p = text;
    count = 0;
    for (int i = 0; i < length; i++) {
        if (p[i] == ' ') {
            count++;
        }
    }
    unsigned long resultLength = length + count * 2 + 1;
    char *result = malloc(resultLength*sizeof(char));
    
    int i;
    char *trackPointer;
    
    trackPointer = text + length - 1;
    i = (int)resultLength - 2;
    while (i >= 0 && trackPointer != NULL) {
        char currentChar;
        currentChar = *trackPointer;
        
        if (currentChar == ' ') {
            result[i] = '0';
            result[--i] = '2';
            result[--i] = '%';
        } else {
            result[i] = currentChar;
        }
        i--;
        trackPointer--;
    }
    result[resultLength - 1] = '\0';
    return result;
}

void testFunc(void) {
    char *text;
    unsigned long length;
    char *result;
    
    text = "hello world";
    length = strlen(text);
    
    result = replaceWhiteSpace(text, length);
    
    char *tmpP;
    tmpP = result;
    while (*tmpP != '\0') {
        printf("%c", *(tmpP++));
    }
    printf("\n----\n");
}
