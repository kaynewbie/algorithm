//
//  roman-to-int.c
//  algorithm
//
//  Created by Kai on 2019/7/16.
//  Copyright © 2019 kai. All rights reserved.
//

#include "roman-to-int.h"
#include "stdbool.h"

/*
 https://leetcode.com/problems/roman-to-integer/
 
 Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
 
 Symbol       Value
 I             1
 V             5
 X             10
 L             50
 C             100
 D             500
 M             1000
 For example, two is written as II in Roman numeral, just two one's added together.
 Twelve is written as, XII, which is simply X + II.
 The number twenty seven is written as XXVII, which is XX + V + II.
 
 Roman numerals are usually written largest to smallest from left to right.
 However, the numeral for four is not IIII. Instead, the number four is written as IV.
 Because the one is before the five we subtract it making four.
 The same principle applies to the number nine, which is written as IX.
 There are six instances where subtraction is used:
 
 I can be placed before V (5) and X (10) to make 4 and 9.
 X can be placed before L (50) and C (100) to make 40 and 90.
 C can be placed before D (500) and M (1000) to make 400 and 900.
 Given a roman numeral, convert it to an integer.
 Input is guaranteed to be within the range from 1 to 3999.
 */

int value(char c);

int romanToInt(char * s){
    int result = 0;
    int v1;
    int v2;
    
    while (*s != '\0') {
        v1 = value(*s);
        
        if (*(s + 1) != '\0') {
            v2 = value(*(s + 1));
            if (v1 >= v2) {
                result += v1;
            } else {
                result += v2 - v1;
                s++;
            }
        } else {
            result += v1;
        }
        s++;
    }
    
    return result;
}

int value(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

//1904
void testRomanToInt1() {
    int result;
    char *input = "MCMIV";
    result = romanToInt(input);
    printf("Roman numerals %s to integer is %d\n", input, result);
}

//0
void testRomanToInt2() {
    int result;
    char *input = "";
    result = romanToInt(input);
    printf("Roman numerals %s to integer is %d\n", input, result);
}

//14
void testRomanToInt3() {
    int result;
    char *input = "XIV";
    result = romanToInt(input);
    printf("Roman numerals %s to integer is %d\n", input, result);
}

//3
void testRomanToInt4() {
    int result;
    char *input = "III";
    result = romanToInt(input);
    printf("Roman numerals %s to integer is %d\n", input, result);
}

//58
void testRomanToInt5() {
    int result;
    char *input = "LVIII";
    result = romanToInt(input);
    printf("Roman numerals %s to integer is %d\n", input, result);
}

void testRomainToInt(void) {
    testRomanToInt1();
    testRomanToInt2();
    testRomanToInt3();
    testRomanToInt4();
    testRomanToInt5();
}
