//
//  question-23.c
//  algorithm
//
//  Created by Kai on 2019/8/2.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-23.h"
#include "linked-list.h"

/*
 一个单向链表，可能存在环（最后一个节点的 next 指向链表中的其它节点），找到环的入口。
 */

ListNode *meetingNode(ListNode *list);

/*
 1. 先找到环中一个节点
 2. 再从节点出发，计算环的长度 k
 3. 声明两个指针，一个先走 k 步，然后两个环保持同步前进，最终会在环的入口处相遇
 */
ListNode *entryNodeOfLoop(ListNode *list) {
    ListNode *meetNode = meetingNode(list);
    if (meetNode == NULL) {
        return NULL;
    }
    
    int length = 1;
    ListNode *p = meetNode->next;
    while (p != meetNode) { // 计算环的长度
        p = p->next;
        length++;
    }
    
    p = list;
    ListNode *p2 = list;
    for (int i = 0; i < length; i++) { // p 先走出 length 步
        p = p->next;
    }
    while (p != p2) { // 两个指针每次都前进一步
        p = p->next;
        p2 = p2->next;
    }
    return p;
}

/*
 声明两个指针 p1 和 p2，p1 一次前进一步，p2 一次前进两步，如果链表存在环，两个指针会在链表中的某一个节点相遇
 */
ListNode *meetingNode(ListNode *list) {
    ListNode *p1, *p2;
    
    if (list == NULL) {
        return NULL;
    }
    p1 = list;
    p2 = p1->next;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1 == p2) {
            return p1;
        }
        p1 = p1->next;
        p2 = p2->next;
        if (p2 != NULL) {
            p2 = p2->next;
        }
    }
    return NULL;
}

// MARK:- Test
/*
 
 */
void testEntryNodeOfLoop1(void) {
    ListNode *list = NULL;
    ListNode **p = &list;
    
    int length = 6;
    for (int i = 0; i < length; i++) { // 生成单向不循环链表
        insertNode(p, i + 1);
    }
    
    ListNode *lastNode = list;
    while (lastNode->next != NULL) { // 找到链表末尾节点
        lastNode = lastNode->next;
    }
    ListNode *entryNode = list;
    int lengthOfLoop = 4; // 给定环长度为 4
    for (int i = 0; i < length - lengthOfLoop; i++) { // 找到环的入口
        entryNode = entryNode->next;
    }
    lastNode->next = entryNode;
    
    ListNode *result = entryNodeOfLoop(list);
    printf("%p: %d, %p: %d\n", entryNode, entryNode->value, result, result->value);
}

void testEntryNodeOfLoop(void) {
    testEntryNodeOfLoop1();
}
