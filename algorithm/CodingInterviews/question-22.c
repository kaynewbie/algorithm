//
//  question-22.c
//  algorithm
//
//  Created by Kai on 2019/7/21.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-22.h"
#include "linked-list.h"

/*
 单向链表中，找到倒数第 k 个节点。要求只遍历一次链表
 */

int findKthNodeFormTail(ListNode *list, int k) {
    ListNode *p = list;
    ListNode *preP;
    for (int i = 1; i <= k - 1; i++) {
        if (p == NULL) {
            return -1;
        }
        p = p->next;
    }
    preP = list;
    while (p->next != NULL) {
        p = p->next;
        preP = preP->next;
    }
    return preP->value;
}

/**
 list: 1->2->3
 k = 2
 result = 2
 */
void testFindKthNodeFormTail1() {
    ListNode *list = NULL;
    ListNode **p = &list;
    insertNode(p, 1);
    insertNode(p, 2);
    insertNode(p, 3);
    printList(list);
    int k = 2;
    int result = findKthNodeFormTail(list, k);
    printf("%dth from tail value is %d\n", k, result);
}

/**
 list: 1
 k = 1
 result = 1
 */
void testFindKthNodeFormTail2() {
    ListNode *list = NULL;
    ListNode **p = &list;
    insertNode(p, 1);
    int k = 1;
    int result = findKthNodeFormTail(list, k);
    printList(list);
    printf("%dth from tail value is %d\n", k, result);
}

/**
 list: 1->3->10->23->44->51->6
 k = 3
 result = 44
 */
void testFindKthNodeFormTail3() {
    ListNode *list = NULL;
    ListNode **p = &list;
    insertNode(p, 1);
    insertNode(p, 3);
    insertNode(p, 10);
    insertNode(p, 23);
    insertNode(p, 44);
    insertNode(p, 51);
    insertNode(p, 6);
    int k = 3;
    int result = findKthNodeFormTail(list, k);
    printList(list);
    printf("%dth from tail value is %d\n", k, result);
}

/**
 list: 1->3->10->23->44->51->6
 k = 7
 result = 1
 */
void testFindKthNodeFormTail4() {
    ListNode *list = NULL;
    ListNode **p = &list;
    insertNode(p, 1);
    insertNode(p, 3);
    insertNode(p, 10);
    insertNode(p, 23);
    insertNode(p, 44);
    insertNode(p, 51);
    insertNode(p, 6);
    int k = 7;
    int result = findKthNodeFormTail(list, k);
    printList(list);
    printf("%dth from tail value is %d\n", k, result);
}

void testFindKthNodeFormTail(void) {
    testFindKthNodeFormTail1();
    testFindKthNodeFormTail2();
    testFindKthNodeFormTail3();
    testFindKthNodeFormTail4();
}
