//
//  queue.h
//  algorithm
//
//  Created by Kai on 2019/7/7.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef queue_h
#define queue_h

#include <stdio.h>
#include "stdbool.h"

typedef struct queue {
    void *data;//实际保存数据的内存指针
    int capacity;//队列容量
    int eleSize;//元素大小
    //队首元素索引，出队后队首地址空出，不要立即前移后续元素，等队列要满的时候再去移动。
    int firstEleIndex;
    int lastEleIndex;//队列末尾元素索引
}Queue;

/**
 创建队列

 @param eleSize 元素大小
 @param capacity 队列容量
 */
Queue *createQueue(int eleSize, int capacity);

/**
 入队

 @param source 需要入队的数据
 @return 入队是否成功
 */
bool enqueue(Queue *queue, void *source);

/**
 出队

 @param dest 需要出队的数据
 @return 出队是否成功
 */
bool dequeue(Queue *queue, void *dest);

/**
 队列头部元素
 */
void *queueHead(Queue *queue);

/**
 遍历队列

 @param queue 需要遍历的队列
 @param handler 遍历回调，回调参数是当前元素
 */
void enemarateQueue(Queue *queue, void(*handler)(void *));


void testQueue(void);

#endif /* queue_h */
