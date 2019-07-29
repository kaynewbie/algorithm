//
//  remove-duplicates-from-sorted-list.c
//  algorithm
//
//  Created by Kai on 2019/7/29.
//  Copyright © 2019 kai. All rights reserved.
//

#include "remove-duplicates-from-sorted-list.h"
#include "stdbool.h"
#include "stdlib.h"

/*
 https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
bool isDuplicate(ListNode *pre, ListNode *curr);

/*
 声明两个指针，一个指向遍历过程中的当前元素，另一个指向前一个元素
 t = O(n), s = O(1)
 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    ListNode *pre, *curr;
    
    if (head == NULL) {
        return NULL;
    }
    pre = head;
    curr = head->next;
    
    while (curr != NULL) {
        if (isDuplicate(pre, curr)) {
            pre->next = curr->next;
            free(curr);
            curr = pre->next;
        } else {
            pre = curr;
            curr = curr->next;
        }
    }
    return head;
}

/**
 判断当前元素在链表中是否重复
 */
bool isDuplicate(ListNode *pre, ListNode *curr) {
//    while (pre != NULL && pre != curr) {
//        if (pre->val == curr->val) {
//            return true;
//        }
//        pre = pre->next;
//    }
    return pre->val == curr->val;
}

// MARK:- Test

static ListNode *p_insertNode(ListNode **p, int value) {
    if (p == NULL) {
        return NULL;
    }
    ListNode *newNode;
    newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->val = value;
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
    return newNode;
}

static void printList(ListNode *list) {
    int i = 0;
    ListNode *currentNode = list;
    while (currentNode != NULL) {
        printf("Node%d=%d\n", i++, currentNode->val);
        currentNode = currentNode->next;
    }
}

/*
 list: 1->3->3
 */
void testRemoveDuplicatesinSortedList1(void) {
    ListNode *list = NULL;
    ListNode **p1 = &list;
    p_insertNode(p1, 1);
    p_insertNode(p1, 3);
    p_insertNode(p1, 3);
    
    printf("--------------------------------\n");
    printf("before delete\n");
    printList(list);
    ListNode *result = deleteDuplicates(list);
    printf("after delete\n");
    printList(result);
}

/*
 list: NULL
 */
void testRemoveDuplicatesinSortedList2(void) {
    ListNode *list = NULL;
//    ListNode **p1 = &list;
//    p_insertNode(p1, 1);
//    p_insertNode(p1, 3);
//    p_insertNode(p1, 3);
    printf("--------------------------------\n");
    printf("before delete\n");
    printList(list);
    ListNode *result = deleteDuplicates(list);
    printf("after delete\n");
    printList(result);
}

/*
 list: 1->1->1->2->2->3
 */
void testRemoveDuplicatesinSortedList3(void) {
    ListNode *list = NULL;
    ListNode **p1 = &list;
    p_insertNode(p1, 1);
    p_insertNode(p1, 1);
    p_insertNode(p1, 1);
    p_insertNode(p1, 2);
    p_insertNode(p1, 2);
    p_insertNode(p1, 3);
    printf("--------------------------------\n");
    printf("before delete\n");
    printList(list);
    ListNode *result = deleteDuplicates(list);
    printf("after delete\n");
    printList(result);
}

/*
 list: 1->1->1->2->2->3->3->3
 */
void testRemoveDuplicatesinSortedList4(void) {
    ListNode *list = NULL;
    ListNode **p1 = &list;
    p_insertNode(p1, 1);
    p_insertNode(p1, 1);
    p_insertNode(p1, 1);
    p_insertNode(p1, 2);
    p_insertNode(p1, 2);
    p_insertNode(p1, 3);
    p_insertNode(p1, 3);
    p_insertNode(p1, 3);
    printf("--------------------------------\n");
    printf("before delete\n");
    printList(list);
    ListNode *result = deleteDuplicates(list);
    printf("after delete\n");
    printList(result);
}

void testRemoveDuplicatesinSortedList(void) {
    testRemoveDuplicatesinSortedList1();
    testRemoveDuplicatesinSortedList2();
    testRemoveDuplicatesinSortedList3();
    testRemoveDuplicatesinSortedList4();
}
