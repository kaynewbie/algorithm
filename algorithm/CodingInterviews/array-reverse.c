//
//  array-reverse.c
//  algorithm
//
//  Created by Kai on 2019/7/11.
//  Copyright © 2019 kai. All rights reserved.
//

#include "array-reverse.h"

/*
 二分查找，判断目标元素是否大于后一个元素，是：下一个元素开始是旋转；否：未找到
 */
int reversedArray(int p[], int length, int target) {
    int start, end, mid;
    
    start = 0;
    end = length - 1;
    while (end >= start) {
        mid = (start + end) >> 1;
        
        if (p[mid] == target) {
            return mid;
        }
        if (p[mid] > p[start]) {//左边是递增的
            if (target > p[mid]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        } else {//右边是递增的 或 p[mid]==p[start]
            if (target > p[mid] && target <= p[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    
    return -1;
}

void testreversedArray1(void) {
    const int length = 10;
    int p[length] = {6, 7, 8, 9, 0, 1, 2, 3, 4, 5};
    int target = 0;
    int result = reversedArray(p, length, target);
    printf("testreversedArray1 result = %d\n", result);
}

void testreversedArray2(void) {
    const int length = 5;
    int p[length] = {1, 1, 1, 1, 2};
    int target = 2;
    int result = reversedArray(p, length, target);
    printf("testreversedArray2 result = %d\n", result);
}

// MARK:- 方法二
/*
 旋转一个递增的数组，在此数组中查找某个值。
 另外的解题思路：代码实现上的优化，时间复杂度上相较上面方法并没有更好。
 原文：https://blog.csdn.net/bendaai/article/details/80059676
 */

#include "limits.h"

const int diff = INT_MAX >> 1;
// 第二个序列的元素都增大，查找时，可以把原序列看成一个递增的完整序列。
// 这里假定加了 diff 后，第二个序列元素能大于第一个序列元素。
int valueInSecondSequence(int value, int start) {
    return value < start ? value + diff : value;
}

int reversedArray1(int p[], int length, int target) {
    int start, end, mid;
    
    start = 0;
    end = length - 1;
    mid = 0;
    
    while (end >= start) {
        mid = (start + end) >> 1;
        
        if (target == p[mid]) {
            return mid;
        }
        int targetAddDiff = valueInSecondSequence(target, p[0]);
        int midAddDiff = valueInSecondSequence(p[mid], p[0]);
        if (targetAddDiff > midAddDiff) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return -1;
}

void testreversedArray3(void) {
    const int length = 5;
    int p[length] = {22, 1, 3, 5, 9};
    int target = 3;
    int result = reversedArray1(p, length, target);
    printf("reversedArray1 result = %d\n", result);
}
