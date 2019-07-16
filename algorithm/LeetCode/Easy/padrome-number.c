//
//  padrome-number.c
//  algorithm
//
//  Created by Kai on 2019/7/16.
//  Copyright © 2019 kai. All rights reserved.
//

#include "padrome-number.h"
#include "stdbool.h"
#include "reverse-integer.h"
#include "limits.h"

/*
 https://leetcode.com/problems/palindrome-number/
 */

bool isPalindrome(int x){
    if (x < 0) {
        return false;
    }
    int reversed = reverse(x);
    return x == reversed;
}

void testIsPalindrome(void) {
    int value = 121;
    bool result = isPalindrome(value);
    char *format = result ? "%d is a palindrome" : "%d is NOT a palindrome";
    printf(format, value);
}
