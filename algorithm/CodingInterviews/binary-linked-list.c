//
//  binary-linked-list.c
//  algorithm
//
//  Created by Kai on 2019/8/18.
//  Copyright © 2019 kai. All rights reserved.
//

#include "binary-linked-list.h"
#include <stdlib.h>

// 根据数据创建双向链表
BinaryList *createBinaryLinkedList(int *nums, int length) {
    BinaryList *list;
    BinaryListNode *node;
    BinaryListNode *tail;
    
    list = NULL;
    tail = NULL;
    
    for (int i = 0; i < length; i++) {
        node = malloc(sizeof(BinaryListNode));
        node->val = nums[i];
        node->pre = tail;
        node->next = NULL;
        
        if (i == 0) { // 保留头结点引用
          list = node;
        } else { // 设置上一个节点的 next 指针
            tail->next = node;
        }
        tail = node;
    }
    return list;
}

// 反转双向链表
void reverseBinaryLinkedList(BinaryList **list) {
    if (list == NULL) return;
    
    BinaryListNode *current;
    BinaryListNode *tmp;
    
    current = *list;
    tmp = NULL;
    
    while (current != NULL) {
        // 交换当前节点的 pre 和 next 指针
        tmp = current->next;
        current->next = current->pre;
        current->pre = tmp;
        
        // 保留当前节点，当 current->pre == NULL 的时候，tmp 就是反转后的头结点。
        tmp = current;
        // 交换当前节点的 pre 和 next 后，通过 pre 指针往后遍历。
        current = current->pre;
    }
    *list = tmp;
}

// MARK:- 打印链表

void printBinaryList(BinaryList *list) {
    printf("list: ");
    while (list != NULL) {
        printf("%d ", list->val);
        list = list->next;
    }
    printf("\n");
}

// MARK:- 测试创建双向链表

void testCreateBinaryLinkedList1(void) {
    const int length = 5;
    int nums[length] = {1, 2, 3, 4, 5};
    BinaryList *list = createBinaryLinkedList(nums, length);
    
    printBinaryList(list);
}

void testCreateBinaryLinkedList2(void) {
    const int length = 1;
    int nums[length] = {1};
    BinaryList *list = createBinaryLinkedList(nums, length);
    
    printBinaryList(list);
}

void testCreateBinaryLinkedList3(void) {
    const int length = 10;
    int nums[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinaryList *list = createBinaryLinkedList(nums, length);
    
    printBinaryList(list);
}

void testCreateBinaryLinkedList(void) {
    testCreateBinaryLinkedList1();
    testCreateBinaryLinkedList2();
    testCreateBinaryLinkedList3();
}

// MARK:- 测试反转双向链表

void testReverseBinaryLinkedList1(void) {
    const int length = 5;
    int nums[length] = {1, 2, 3, 4, 5};
    printf("反转前\n");
    BinaryList *list = createBinaryLinkedList(nums, length);
    printBinaryList(list);
    
    printf("反转后\n");
    reverseBinaryLinkedList(&list);
    printBinaryList(list);
}

void testReverseBinaryLinkedList2(void) {
    const int length = 1;
    int nums[length] = {1};
    printf("反转前\n");
    BinaryList *list = createBinaryLinkedList(nums, length);
    printBinaryList(list);
    
    printf("反转后\n");
    reverseBinaryLinkedList(&list);
    printBinaryList(list);
}

void testReverseBinaryLinkedList3(void) {
    const int length = 10;
    int nums[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("反转前\n");
    BinaryList *list = createBinaryLinkedList(nums, length);
    printBinaryList(list);
    
    printf("反转后\n");
    reverseBinaryLinkedList(&list);
    printBinaryList(list);
}

void testReverseBinaryLinkedList(void) {
    testReverseBinaryLinkedList1();
    testReverseBinaryLinkedList2();
    testReverseBinaryLinkedList3();
}
