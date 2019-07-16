//
//  reverse-integer.c
//  algorithm
//
//  Created by Kai on 2019/7/16.
//  Copyright © 2019 kai. All rights reserved.
//

#include "reverse-integer.h"
#include "math.h"

/*
 Given a 32-bit signed integer, reverse digits of an integer.
 
 Example 1:
 Input: 123
 Output: 321
 
 Example 2:
 Input: -123
 Output: -321
 
 Example 3:
 Input: 120
 Output: 21
 */

int reverseCore(int x, int *length) {
    if (x < 10) {
        return x;
    }
    int remainder = x % 10;
    int quotient = x / 10;
    
    int value = reverseCore(quotient, length);
    int current = remainder * (int)pow(10, ++(*length));
    return current + value;
}

int reverse(int x) {
    int length = 0;
    int sign = x >= 0 ? 1 : -1;
    int result = sign * reverseCore(sign * x, &length);
    return result;
}

void testReverse(void) {
    int target = -0;
    int result = reverse(target);
    printf("result=%d\n", result);
}
