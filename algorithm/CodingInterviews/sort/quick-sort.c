//
//  quick-sort.c
//  algorithm
//
//  Created by Kai on 2019/7/11.
//  Copyright © 2019 kai. All rights reserved.
//

#include "quick-sort.h"
#include "stdlib.h"
#include <sys/time.h>

/**
 交换两个变量的值。

 @param p 一个待交换变量的地址
 @param q 另一个待交换变量的地址
 */
void swap(int *p, int *q) {
    if (p == NULL || q == NULL) {
        return;
    }
    int temp = *p;
    *p = *q;
    *q = temp;
}

/**
 获取一个参考值，遍历数组 start 和 end-1 索引区间内的元素，
 小于等于参考值的放到索引左边，大于的放到右边，
 过程中，记录小于等于参考值的元素数量，并返回该数。
 
 @param p 数组指针
 @param start 当前排序区间起始索引
 @param end 当前排序区间终止索引
 @return 当次排序的随机索引值
 */
int partition(int *p, int start, int end) {
    int randomIdx;
    int small;
    
    //随机索引这里用中间索引
    randomIdx = (start + end) >> 1;
    small = start - 1;
    
    swap(p + randomIdx, p + end);
    for (int i = start; i < end; i++) {
        if (*(p+i) <= *(p+end)) {
            small++;
            if (small != i) {
                swap(p+i, p+small);
            }
        }
    }
    small++;
    swap(p+small, p+end);
    
    return small;
}

/**
 快速排序驱动函数
 */
void quickSort(int *p, int start, int end) {
    if (start == end) {
        return;
    }
    
    int index = partition(p, start, end);
    if (index > start) {
        quickSort(p, start, index - 1);
    }
    if (index < end) {
        quickSort(p, index + 1, end);
    }
}

/**
 元素大小为0～range内的随机数组
 */
int *randomArray(int length, int range) {
    int *p = malloc(sizeof(int) * length);

    srand(time(0));
    
    int value;
    for (int i = 0; i < length; i++) {
        value = rand() % range;
        *(p + i) = value;
    }
    return p;
}

void printArray(int p[], int length) {
    printf("array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

void testQuickSort(void) {
    int length = 30;
    int *p = randomArray(length, 1000);
    quickSort(p, 0, length - 1);
    
    printArray(p, length);
}
