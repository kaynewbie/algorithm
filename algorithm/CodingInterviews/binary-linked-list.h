//
//  binary-linked-list.h
//  algorithm
//
//  Created by Kai on 2019/8/18.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef binary_linked_list_h
#define binary_linked_list_h

#include <stdio.h>

/*
 反转一个双向链表
 */

struct BinaryListNode {
    int val;
    struct BinaryListNode *pre;
    struct BinaryListNode *next;
};
typedef struct BinaryListNode BinaryListNode;
typedef BinaryListNode BinaryList;


/**
 根据数据创建双向链表

 @param int 整型数组
 @param int 数组长度
 @return 双向链表头结点指针
 */
BinaryList *createBinaryLinkedList(int *, int);

/**
 反转双向链表

 @param BinaryList 入参是一个指向双向链表的指针的指针。因为会改变引用指针的指向，所以要用二级指针。
 */
void reverseBinaryLinkedList(BinaryList **);

// MARK:- 测试方法
void testCreateBinaryLinkedList(void);
void testReverseBinaryLinkedList(void);

#endif /* binary_linked_list_h */
