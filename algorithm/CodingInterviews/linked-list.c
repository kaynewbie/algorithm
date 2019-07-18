//
//  linked-list.c
//  algorithm
//
//  Created by Kai on 2019/7/4.
//  Copyright © 2019 kai. All rights reserved.
//

#include "linked-list.h"
#include "stdbool.h"
#include "stdlib.h"


/**
 打印链表
 */
void printList(ListNode *list) {
    int i = 0;
    ListNode *currentNode = list;
    while (currentNode != NULL) {
        printf("Node%d=%d\n", i++, currentNode->value);
        currentNode = currentNode->next;
    }
}

/**
 链表末尾插入新节点。

 @param p 指向指针的指针。因为链表可能为空，需要改变指向链表的指针指向。
 @param value 新增节点的值。
 */
void insertNode(ListNode **p, int value) {
    if (p == NULL) {
        return;
    }
    ListNode *newNode;
    newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->value = value;
    newNode->next = NULL;
    
    ListNode *currentNode = *p;
    if (currentNode == NULL) {
        // 不能用 currentNode = newNode;
        *p = newNode;
    } else {
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

/**
 移除某个节点。

 @param p 如果链表只有一个节点，删除后，HEAD 指针指向 NULL
 @param value 待移除节点
 @return 被移除的节点
 */
ListNode *removeNode(ListNode **p, int value) {
    ListNode *currentNode = *p;
    ListNode *previousNode = *p;
    
    // 链表本身为空
    if (currentNode == NULL) {
        return NULL;
    } else if (currentNode->value == value) {
        *p = currentNode->next;
        currentNode->next = NULL;
        return currentNode;
    }

    while (currentNode != NULL && currentNode->value != value) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    previousNode->next = currentNode->next;
    return currentNode;
}

/**
 链表中查找第一个匹配的节点
 */
bool findFirst(ListNode *list, int value) {
    ListNode *currentNode = list;
    while (currentNode != NULL) {
        if (currentNode->value == value) {
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}

void testList(void) {
    ListNode *list = NULL;
    ListNode **p = &list;
    
    insertNode(p, 23);
    insertNode(p, 24);
    insertNode(p, 6);
    
    printList(list);
    
    printf("--------- after delete -------------\n");
    
    removeNode(p, 23);
    removeNode(p, 24);
    removeNode(p, 6);
    removeNode(p, 61);
    
    printList(list);
}

ListNode *reverseListCore(ListNode *node, ListNode **head) {
    if (node->next == NULL) {
        *head = node;
        return node;
    }
    ListNode *nextNode = reverseListCore(node->next, head);
    nextNode->next = node;
    return node;
}

/**
 逆转单向链表，要求空间复杂度 O(1)
 */
ListNode *reverseList(ListNode **list) {
    if (*list == NULL) {
        return NULL;
    }
    ListNode *result = reverseListCore(*list, list);
    result->next = NULL;
    
    return *list;
}

void testReverseSingleDirectionList1() {
    ListNode *list = NULL;
    ListNode **p = &list;
    insertNode(p, 23);
    insertNode(p, 24);
    insertNode(p, 6);
    insertNode(p, 3);
    insertNode(p, 2);
    
    printf("\n----------testReverseSingleDirectionList1------------\n");
    printList(list);
    printf("\n--------- reverse -------------\n");
    ListNode *result = reverseList(p);
    printList(result);
}

void testReverseSingleDirectionList2() {
    ListNode *list = NULL;
    ListNode **p = &list;
    
    printf("\n----------testReverseSingleDirectionList2------------\n");
    printList(list);
    ListNode *result = reverseList(p);
    printf("\n--------- reverse -------------\n");
    printList(result);
}

void testReverseSingleDirectionList(void) {
    testReverseSingleDirectionList1();
    testReverseSingleDirectionList2();
}
