//
//  queue.c
//  algorithm
//
//  Created by Kai on 2019/7/7.
//  Copyright © 2019 kai. All rights reserved.
//

#include "queue.h"
#include "stdlib.h"
#include "string.h"

/**
 创建队列
 
 @param eleSize 元素大小
 @param capacity 队列容量
 */
Queue *createQueue(int eleSize, int capacity) {
    if (eleSize < 0 || capacity < 0) {
        return NULL;
    }
    Queue *queue = malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->eleSize = eleSize;
    queue->data = malloc(sizeof(eleSize) * capacity);
    queue->lastEleIndex = -1;
    queue->firstEleIndex = -1;
    return queue;
}

void expandQueue(Queue *queue) {
    if (queue == NULL) {
        return;
    }
    int newCapacity;
    if (queue->capacity == 0) {
        newCapacity = 1;
    } else {
        newCapacity = queue->capacity * 2;
    }
    queue->data = realloc(queue->data, queue->eleSize * newCapacity);
    queue->capacity *= 2;
}

/**
 队列元素前移，填补出队造成的内存空缺。
 
 @return 是否能够前移。
 */
bool forwardQueue(Queue *queue) {
    return false;
}

/**
 入队
 
 @param source 需要入队的数据
 @return 入队是否成功
 */
bool enqueue(Queue *queue, void *source) {
    if (queue == NULL) {
        return false;
    }
    // 队列已满，先尝试能否前移，再决定是否扩充容量
    if (queue->capacity == queue->lastEleIndex + 1) {
        if (forwardQueue(queue) == false) {
            expandQueue(queue);
        }
    }
    queue->lastEleIndex++;
    void *dst = queue->data+(queue->lastEleIndex * queue->eleSize);
    memcpy(dst, source, queue->eleSize);
    if (queue->firstEleIndex == -1) {
        queue->firstEleIndex = 0;
    }
    return true;
}

/**
 出队
 
 @param dst 出队数据写入的地址
 @return 出队是否成功
 */
bool dequeue(Queue *queue, void *dst) {
    if (queue == NULL) {
        return false;
    }
    if (queue->firstEleIndex == -1) {
        return false;
    }
    void *source = queue->data+(queue->firstEleIndex * queue->eleSize);
    memcpy(dst, source, queue->eleSize);
    if (queue->firstEleIndex == queue->lastEleIndex) {
        queue->firstEleIndex = -1;
        queue->lastEleIndex = -1;
    } else {
        queue->firstEleIndex++;
    }
    return true;
}

/**
 队列头部元素
 */
void *queueHead(Queue *queue) {
    return NULL;
}

/**
 遍历队列
 
 @param queue 需要遍历的队列
 @param handler 遍历回调，回调参数是当前元素
 */
void enumerateQueue(Queue *queue, void(*handler)(int, void *)) {
    for (int i = queue->firstEleIndex; i <= queue->lastEleIndex && i > -1; i++) {
        void *ele = queue->data+(i * queue->eleSize);
        void *dst = malloc(sizeof(queue->eleSize));
        memcpy(dst, ele, queue->eleSize);
        handler(i, dst);
    }
}

void printEle(int idx, void *ele) {
    int *p = ele;
    printf("value%d=%d\n", idx, *p);
}

void testQueue() {
    Queue *q = createQueue(sizeof(int), 10);
    
    int ele1 = 6;
    int ele2 = 23;
    int ele3 = 34;
    
    enqueue(q, &ele1);
    enqueue(q, &ele2);
    enqueue(q, &ele3);
    enumerateQueue(q, printEle);
    
    int a, b, c;
    dequeue(q, &a);
    dequeue(q, &b);
    dequeue(q, &c);
//    printf("dequeue1=%d\n", a);
//    printf("dequeue2=%d\n", b);
//    printf("dequeue3=%d\n", c);
    
    enumerateQueue(q, printEle);
}
