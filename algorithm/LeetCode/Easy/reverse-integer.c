//
//  reverse-integer.c
//  algorithm
//
//  Created by Kai on 2019/7/16.
//  Copyright © 2019 kai. All rights reserved.
//

#include "reverse-integer.h"
#include "math.h"
#include "limits.h"

/*
 Given a 32-bit signed integer, reverse digits of an integer.
 
 Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
 For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

 
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

long reverseCore(long x, int *length) {
    if (x < 10) {
        return x;
    }
    long remainder = x % 10;
    long quotient = x / 10;
    
    long value = reverseCore(quotient, length);
    long current = remainder * (long)pow(10, ++(*length));
    return current + value;
}

int reverse(int x) {
    int length = 0;
    int sign = x >= 0 ? 1 : -1;
    long result = sign * reverseCore(sign * (long)x, &length);
    if (result >= INT_MIN && result <= INT_MAX) {
        return (int)result;
    } else {
        return 0;
    }
}

/*
 例子1：1534236469 -> 1056389759，翻转的时候可能超出范围。
 例子2：-2147483648 -> 0 如果直接取反，超出 32 位
 32 bits range: [-2147483648, 2147483647]
 LeetCode 上错误错误记录：https://leetcode.com/problems/reverse-integer/submissions/
 */
void testReverse(void) {
    int target = INT_MIN;
    int result = reverse(target);
    printf("result=%d\n", result);
}
