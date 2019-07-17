//
//  longest-common-prefix.c
//  algorithm
//
//  Created by Kai on 2019/7/17.
//  Copyright © 2019 kai. All rights reserved.
//

#include "longest-common-prefix.h"
#include "stdlib.h"
#include "stdbool.h"

/*
 https://leetcode.com/problems/longest-common-prefix/
 
 Write a function to find the longest common prefix string amongst an array of strings.
 If there is no common prefix, return an empty string "".
 */

char *longestCommonPrefix(char ** strs, int strsSize){
    int capacity = 5;
    char *pInFirstStr = *strs;
    char *result = malloc(sizeof(char) * capacity);
    int idx = 0;
    
    int i;
    char c;
    bool success;
    while (*(pInFirstStr + idx) != '\0') {
        printf("current char: %c\n", *(pInFirstStr + idx));
        success = true;
        for (i = 0; i < strsSize; i++) {
            c = *(*(strs + i) + idx);
            if (*(pInFirstStr + idx) != c) {
                success = false;
                break;
            }
        }
        if (!success) {
            break;
        }
        if (idx >= capacity) {//extent
            capacity += 10;
            result = realloc(result, capacity);
        }
        result[idx] = *(pInFirstStr + idx);
        idx++;
    }
    return result;
}

/*
 array: [""]
 prefix: ""
 */
void testLongestCommonPrefix1() {
    char *strs[1] = {""};
    char *prefix = longestCommonPrefix(strs, 1);
    printf("prefix: %s\n", prefix);
}

/*
 array: ["flow", "flower", "flat"]
 prefix: "fl"
 */
void testLongestCommonPrefix2() {
    char *strs[3] = {"flow", "flower", "flat"};
    char *prefix = longestCommonPrefix(strs, 3);
    printf("prefix: %s\n", prefix);
}

/*
 array: ["flower","flow","flight"]
 prefix: "fl"
 */
void testLongestCommonPrefix3() {
    char *strs[3] = {"flower","flow","flight"};
    char *prefix = longestCommonPrefix(strs, 3);
    printf("prefix: %s\n", prefix);
}

/*
 array: ["king", "kid", "done"]
 prefix: ""
 */
void testLongestCommonPrefix4() {
    char *strs[4] = {"king", "kid", "kitty", "keyboard"};
    char *prefix = longestCommonPrefix(strs, 4);
    printf("prefix: %s\n", prefix);
}

void testLongestCommonPrefix(void) {
    testLongestCommonPrefix1();
    testLongestCommonPrefix2();
    testLongestCommonPrefix3();
    testLongestCommonPrefix4();
    printf("=====%d\n", '\0');
}
