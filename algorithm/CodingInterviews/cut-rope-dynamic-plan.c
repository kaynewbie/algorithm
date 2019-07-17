//
//  cut-rope-dynamic-plan.c
//  algorithm
//
//  Created by Kai on 2019/7/18.
//  Copyright © 2019 kai. All rights reserved.
//

#include "cut-rope-dynamic-plan.h"
#include "stdlib.h"

/**
 长为 n 的绳子，剪成若干段段(m)，使得得到的各段绳子长度的乘积最大。(n > 1, m > 1)
 
 动态规划：
    * 大问题可以划分成多个小问题
    * 每个小问题存在最优解
    * 小问题之间有相互重叠的更小的子问题
    * 从上往下分析问题，从下往上求解问题
 */
int maxProduct(int length) {
    switch (length) {
        case 0:
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        default:
            break;
    }
    int *products = malloc(sizeof(int) * (length + 1));
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;
    
    int max = 0;
    int tmp = 0;
    for (int i = 4; i <= length; i++) {
        max = 0;
        for (int j = 1; j <= length / 2; j++) {
            tmp = products[j] * products[i - j];
            if (tmp > max) {
                printf("[%d, %d]", i, j);
                max = tmp;
            }
        }
        products[i] = max;
    }
    printf(" ===> ");
    return max;
}

void testMaxProduct1() {
    int length = 10;
    int result = maxProduct(length);
    printf("Max product for length:%d is %d\n", length, result);
}

void testMaxProduct2() {
    int length = 0;
    int result = maxProduct(length);
    printf("Max product for length:%d is %d\n", length, result);
}

void testMaxProduct3() {
    int length = 5;
    int result = maxProduct(length);
    printf("Max product for length:%d is %d\n", length, result);
}

void testMaxProduct(void) {
    testMaxProduct1();
    testMaxProduct2();
    testMaxProduct3();
}
