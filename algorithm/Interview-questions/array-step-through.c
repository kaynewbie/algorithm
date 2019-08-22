//
//  array-step-through.c
//  algorithm
//
//  Created by Kai on 2019/8/22.
//  Copyright © 2019 kai. All rights reserved.
//

#include "array-step-through.h"

/*
 遍历数组，每次遍历都是用当前元素值建立一个范围
 */
int arrayStepThrough(int *array, int len) {
    if (array == NULL || len == 0) return 0;
    
    /*
     start: 当前遍历到的范围开始索引
     end: 当前遍历到的范围结束索引
     max: 当前遍历到的范围内元素，最远能到达的位置索引
     idx: 记录找到最远位置时的元素索引
     */
    int start, end, max, idx;
    int steps;// 总计步数
    
    steps = 0;
    start = 0;
    end = 0;
    while (end < len - 1) {// 到达终点
        idx = 0;
        max = 0;
        for (int i = start; i <= end; i++) {// 查找当前范围内元素能到达的最远位置
            if (i + array[i] > max) {
                idx = i;
                max = i + array[i];
            }
        }
        start = idx + 1;
        end = max;
        steps++;
    }
    return steps;
}

// MARK:- 测试

void testArrayStepThrough1(void) {
    const int len = 5;
    int array[len] = {2, 3, 1, 1, 4};
    int result = arrayStepThrough(array, len);
    printf("%s 最少 %d 步\n", __func__, result);
}

void testArrayStepThrough2(void) {
    const int len = 10;
    int array[len] = {5, 4, 3, 2, 1, 2, 1, 3, 4, 1};
    int result = arrayStepThrough(array, len);
    printf("%s 最少 %d 步\n", __func__, result);
}

void testArrayStepThrough(void) {
    testArrayStepThrough1();
    testArrayStepThrough2();
}
