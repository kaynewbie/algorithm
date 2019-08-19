//
//  question-39.c
//  algorithm
//
//  Created by Kai on 2019/8/19.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-39.h"
#include <stdbool.h>

bool checkMoreThanHalf(int *nums, int length, int target);

int moreThanHalfNum(int *nums, int length) {
    if (nums == NULL || length <= 0) {
        return 0;
    }
    int times, result;
    
    times = 0;
    result = 0;
    for (int i = 0; i < length; i++) {
        if (times == 0) {
            result = nums[i];
            times = 1;
        } else if (nums[i] == result) {
            times++;
        } else {
            times--;
        }
    }
    if (!checkMoreThanHalf(nums, length, result)) {
        return 0;
    }
    return result;
}

// MARK:- 辅助函数

bool checkMoreThanHalf(int *nums, int length, int target) {
    int times;
    
    times = 0;
    for (int i = 0; i < length; i++) {
        if (nums[i] == target) times++;
    }
    return times > (length >> 1);
}

// MARK:- 测试

void testMoreThanHalfNum1(void) {
    const int length = 5;
    int nums[length] = {1, 2, 3, 2, 2};
    int result = moreThanHalfNum(nums, length);
    printf("%s: %d\n", __func__, result);
}

void testMoreThanHalfNum2(void) {
    const int length = 10;
    int nums[length] = {1, 2, 3, 2, 2, 4, 6, 2, 2, 2};
    int result = moreThanHalfNum(nums, length);
    printf("%s: %d\n", __func__, result);
}

void testMoreThanHalfNum(void) {
    testMoreThanHalfNum1();
    testMoreThanHalfNum2();
}
