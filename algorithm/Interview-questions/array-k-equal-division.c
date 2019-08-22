//
//  array-k-equal-division.c
//  algorithm
//
//  Created by Kai on 2019/8/23.
//  Copyright © 2019 kai. All rights reserved.
//

#include "array-k-equal-division.h"

int arraySum(int *nums, int len);

/**
 数组元素和 k 等分，意味着数组整体的和是 k 的倍数。遍历数组，找出 k 份总和为 sum/k 的子数组。
 
 @param nums 数组
 @param len 长度
 @param k 等分成 k 份
 @return 数组是否支持等分 k 份
 */
bool arrayCanBeKEqualDivision(int *nums, int len, int k) {
    if (nums == NULL || len < k || len < 0) return false;
    
    int sum;
    int count;// 记录元素和为总和 1/k 的结果数量
    
    count = 0;
    sum = arraySum(nums, len);
    const int partSum = sum / k;
    
    if (sum % k != 0) return false;
    
    sum = 0;
    for (int i = 0; i < len; i++) {// 遍历数组
        sum += nums[i];
        if (sum == partSum) {// 得到一份元素和为总和 1/k 的结果
            count++;
            sum = 0;
        }
        if (sum > partSum) return false;
    }
    if (count < k) return false;
    return true;
}

// MARK:- 辅助函数

int arraySum(int *nums, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += nums[i];
    }
    return sum;
}

// MARK:- 测试

void testArrayCanBeKEqualDivision1(void) {
    const int len = 10;
    const int k = 3;
    int nums[len] = {1, 1, 1, 3, 4, 5, 6, 2, 1, 1};
    bool result = arrayCanBeKEqualDivision(nums, len, k);
    printf("%s %s be %d equal division\n", __func__, result ? "CAN" : "CAN NOT", k);
}

void testArrayCanBeKEqualDivision2(void) {
    const int len = 10;
    const int k = 3;
    int nums[len] = {1, 2, 3, 3, 3, 1, 1, 1, 1, 2};
    bool result = arrayCanBeKEqualDivision(nums, len, k);
    printf("%s %s be %d equal division\n", __func__, result ? "CAN" : "CAN NOT", k);
}

void testArrayCanBeKEqualDivision3(void) {
    const int len = 3;
    const int k = 3;
    int nums[len] = {1, 1, 1};
    bool result = arrayCanBeKEqualDivision(nums, len, k);
    printf("%s %s be %d equal division\n", __func__, result ? "CAN" : "CAN NOT", k);
}

void testArrayCanBeKEqualDivision4(void) {
    const int len = 3;
    const int k = 3;
    int nums[len] = {2, 2, 1};
    bool result = arrayCanBeKEqualDivision(nums, len, k);
    printf("%s %s be %d equal division\n", __func__, result ? "CAN" : "CAN NOT", k);
}

void testArrayCanBeKEqualDivision(void) {
    testArrayCanBeKEqualDivision1();
    testArrayCanBeKEqualDivision2();
    testArrayCanBeKEqualDivision3();
    testArrayCanBeKEqualDivision4();
}
