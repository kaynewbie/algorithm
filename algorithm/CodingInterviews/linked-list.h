//
//  linked-list.h
//  algorithm
//
//  Created by Kai on 2019/7/4.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>

/*
 链表操作：增、删、查
 */
typedef struct ListNode {
    int value;
    struct ListNode *next;
} ListNode;

void testList(void);
ListNode *reverseList(ListNode **list);
void printList(ListNode *list);
ListNode *insertNode(ListNode **p, int value);

void testReverseSingleDirectionList(void);
void testDeleteNode(void);

#endif /* linked_list_h */
