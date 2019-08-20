//
//  find-element-count-one-in-n.c
//  algorithm
//
//  Created by Kai on 2019/8/21.
//  Copyright © 2019 kai. All rights reserved.
//

#include "find-element-count-one-in-n.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 记录元素的值和次数
 */
struct Element {
    int val;
    int times;
};
typedef struct Element Element;

// 用数组当做 map，存放元素
struct Map {
    Element *elements;
    int count;
    int capacity;
};
typedef struct Map Map;

Map *createMap(int capacity);
void saveValue(Map *map, int value);
void doMinusForAll(Map *map);
int *fetchValues(Map *map, int *length);
int elementCountInArray(int *nums, int len, int value);

int *findElementsCountMoreThanOneInN(int *array, int length, int n, int *count) {
    if (array == NULL || length <= 0 || n < 2) {
        return NULL;
    }
    Map *map;
    int *result;
    int idx, countToN;
    
    map = createMap(n);
    idx = 0;
    while (idx <= length - n) {
        countToN = 0;
        while (countToN < n) {
            // 每次外层循环，都将 array 中的 n 个元素加入 map
            saveValue(map, array[idx]);
            countToN++;
            idx++;
        }
        // 然后所有元素 times--
        doMinusForAll(map);
    }
    // 可能数组末尾还有不到 n 个元素未遍历到，从 idx 遍历到数组末尾
    int _count;
    for (int i = idx; i < length; i++) {
        _count = elementCountInArray(array, length, array[i]);
        if (_count > (length / n)) {
            saveValue(map, array[i]);
        }
    }
    
    result = fetchValues(map, count);
    return result;
}

// MARK:- 辅助函数

Map *createMap(int capacity) {
    Map *map;
    Element *elements;
    Element *ele;
    
    elements = malloc(sizeof(Element) * capacity);
    for (int i = 0; i < capacity; i++) {
        ele = malloc(sizeof(Element));
        ele->val = 0;
        ele->times = 0;
        elements[i] = *ele;
        free(ele);
    }
    
    map = malloc(sizeof(Map));
    map->elements = elements;
    map->count = 0;
    map->capacity = capacity;
    
    return map;
}

/*
 Map 中增加元素，
    如果超过 capacity，则所以元素 times--，
        此时，如果有元素 times==0，则移除元素，否则，什么都不做；
    否则，找到对应元素，执行 times--。
 */
void saveValue(Map *map, int value) {
    if (map == NULL) return;
    
    int count;
    bool isExit;
    
    isExit = false;
    count = map->capacity;
    for (int i = 0; i < count; i++) {
        if (map->elements[i].val == value) {// 元素已经存在，则增加计数
            isExit = true;
            map->elements[i].times++;
        }
    }
    if (!isExit) {// 元素不存在，分两种情况
        if (map->count < map->capacity) {// 表 **还未存满**，则继续存入新元素，计数置为1
            for (int i = 0; i < map->capacity; i++) {
                if (map->elements[i].val == 0) {
                    map->elements[i].val = value;
                    map->elements[i].times = 1;
                    map->count++;
                    break;
                }
            }
        }
    }
}

void doMinusForAll(Map *map) {
    for (int i = 0; i < map->capacity; i++) {// 表中所有元素执行 times--
        map->elements[i].times--;
        if (map->elements[i].times == 0) {//减完后，元素计数为0，移除元素
            map->elements[i].val = 0;
            map->count--;
        }
    }
}

int elementCountInArray(int *nums, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if (nums[i] == value) {
            count++;
        }
    }
    return count;
}

// 获取 Map 中的元素
int *fetchValues(Map *map, int *length) {
    *length = map->count;

    int *results;
    int idx;
    
    idx = 0;
    results = calloc(*length, sizeof(int));
    for (int i = 0; i < map->capacity; i++) {
        if (map->elements[i].val != 0) {
            results[idx] = map->elements[i].val;
            idx++;
        }
    }
    return results;
}

// MARK:- 测试

void testCreateMap(void) {
    Map *map = createMap(3);
    Element ele = map->elements[0];
    ele.val = 1;
    printf("%p, %d, %d\n", &map->elements[0], map->elements[0].val, map->elements[0].times);
    printf("%p, %d, %d\n", &map->elements[1], map->elements[1].val, map->elements[1].times);
}

void testFindElementsCountMoreThanOneInN1(void) {
    const int len = 10;
    int nums[len] = {1, 2, 3 ,2, 2, 3, 5, 3, 5, 8};
    int n = 4;
    int count;
    
    count = 0;
    int *results = findElementsCountMoreThanOneInN(nums, len, n, &count);
    
    printf("%s 数量超过 1/%d 的元素: ", __func__, n);
    for (int i = 0; i < count; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
}

void testFindElementsCountMoreThanOneInN2(void) {
    const int len = 8;
    int nums[len] = {1, 2, 3 ,2, 2, 3, 5, 3};
    int n = 4;
    int count;
    
    count = 0;
    int *results = findElementsCountMoreThanOneInN(nums, len, n, &count);
    
    printf("%s 数量超过 1/%d 的元素: ", __func__, n);
    for (int i = 0; i < count; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
}

void testFindElementsCountMoreThanOneInN3(void) {
    const int len = 6;
    int nums[len] = {1, 2, 3 ,9, 2, 3};
    int n = 4;
    int count;
    
    count = 0;
    int *results = findElementsCountMoreThanOneInN(nums, len, n, &count);
    
    printf("%s 数量超过 1/%d 的元素: ", __func__, n);
    for (int i = 0; i < count; i++) {
        printf("%d ", results[i]);
    }
    printf("\n");
}

void testFindElementsCountMoreThanOneInN(void) {
    testFindElementsCountMoreThanOneInN1();
    testFindElementsCountMoreThanOneInN2();
    testFindElementsCountMoreThanOneInN3();
}
