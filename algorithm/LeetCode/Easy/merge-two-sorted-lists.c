//
//  merge-two-sorted-lists.c
//  algorithm
//
//  Created by Kai on 2019/7/22.
//  Copyright © 2019 kai. All rights reserved.
//

#include "merge-two-sorted-lists.h"
#include "stdlib.h"

/**
 https://leetcode.com/problems/merge-two-sorted-lists/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
static ListNode *p_insertNode(ListNode **p, int value);
static void printList(ListNode *list);

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        if (l2 == NULL) {
            return NULL;
        } else {
            return l2;
        }
    } else {
        if (l2 == NULL) {
            return l1;
        }
    }
    
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    ListNode *head = NULL;
    ListNode *tail = NULL;
    
    if (p1->val > p2->val) {
        head = p2;
        tail = p2;
        p2 = p2->next;
    } else {
        head = p1;
        tail = p1;
        p1 = p1->next;
    }
    while (p1 != NULL && p2 != NULL) {
        if (p1->val > p2->val) {
            tail->next = p2;
            tail = p2;
            p2 = p2->next;
        } else {
            tail->next = p1;
            tail = p1;
            p1 = p1->next;
        }
    }
    if (p1 == NULL) {
        tail->next = p2;
    }
    if (p2 == NULL) {
        tail->next = p1;
    }
    return head;
}


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

/**
 l1: 1->3->5
 l2: 2->4->6
 result: 1->1->2->3->4->4
 */
void testMergeTwoLists1() {
    ListNode *list1 = NULL;
    ListNode **p1 = &list1;
    p_insertNode(p1, 1);
    p_insertNode(p1, 3);
    p_insertNode(p1, 5);
    
    ListNode *list2 = NULL;
    ListNode **p2 = &list2;
    p_insertNode(p2, 2);
    p_insertNode(p2, 4);
    p_insertNode(p2, 6);
    
    ListNode *result = mergeTwoLists(list1, list2);
    printList(result);
    printf("--------- end ----------\n");
}

/**
 l1: 1->2->4->5
 l2: 1->3->4
 result: 1->1->2->3->4->4->5
 */
void testMergeTwoLists2() {
    ListNode *list1 = NULL;
    ListNode **p1 = &list1;
    p_insertNode(p1, 1);
    p_insertNode(p1, 2);
    p_insertNode(p1, 4);
    p_insertNode(p1, 5);
    
    ListNode *list2 = NULL;
    ListNode **p2 = &list2;
    p_insertNode(p2, 1);
    p_insertNode(p2, 3);
    p_insertNode(p2, 4);
    
    ListNode *result = mergeTwoLists(list1, list2);
    printList(result);
    printf("--------- end ----------\n");
}

/**
 l1: 1->2->4
 l2: 1->3->4->5
 result: 1->1->2->3->4->4->5
 */
void testMergeTwoLists3() {
    ListNode *list1 = NULL;
    ListNode **p1 = &list1;
    p_insertNode(p1, 1);
    p_insertNode(p1, 2);
    p_insertNode(p1, 4);
    
    ListNode *list2 = NULL;
    ListNode **p2 = &list2;
    p_insertNode(p2, 1);
    p_insertNode(p2, 3);
    p_insertNode(p2, 4);
    p_insertNode(p2, 5);
    
    ListNode *result = mergeTwoLists(list1, list2);
    printList(result);
    printf("--------- end ----------\n");
}

/**
 l1: 1->2->4
 l2: 1->5->10->23->43->650
 result: 1->1->2->4->5->10->23->43->650
 */
void testMergeTwoLists4() {
    ListNode *list1 = NULL;
    ListNode **p1 = &list1;
    p_insertNode(p1, 1);
    p_insertNode(p1, 2);
    p_insertNode(p1, 4);
    
    ListNode *list2 = NULL;
    ListNode **p2 = &list2;
    p_insertNode(p2, 1);
    p_insertNode(p2, 5);
    p_insertNode(p2, 10);
    p_insertNode(p2, 23);
    p_insertNode(p2, 43);
    p_insertNode(p2, 650);
    
    ListNode *result = mergeTwoLists(list1, list2);
    printList(result);
    printf("--------- end ----------\n");
}

/**
 l1: empty
 l2: 1->5->10->23->43->650
 result: 1->5->10->23->43->650
 */
void testMergeTwoLists5() {
    ListNode *list1 = NULL;
    
    ListNode *list2 = NULL;
    ListNode **p2 = &list2;
    p_insertNode(p2, 1);
    p_insertNode(p2, 5);
    p_insertNode(p2, 10);
    p_insertNode(p2, 23);
    p_insertNode(p2, 43);
    p_insertNode(p2, 650);
    
    ListNode *result = mergeTwoLists(list1, list2);
    printList(result);
    printf("--------- end ----------\n");
}

void testMergeTwoLists(void) {
    testMergeTwoLists1();
    testMergeTwoLists2();
    testMergeTwoLists3();
    testMergeTwoLists4();
    testMergeTwoLists5();
}
