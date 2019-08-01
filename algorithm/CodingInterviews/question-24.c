//
//  question-24.c
//  algorithm
//
//  Created by Kai on 2019/8/2.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-24.h"
#include "linked-list.h"

/*
 输入一个单向链表，输出翻转后的链表
 */

ListNode *reverseListFunc(ListNode **list) {
    return reverseList(list);
}

void testReverseListFunc(void) {
    ListNode *list = NULL;
    ListNode **p = &list;
    
    int length = 6;
    for (int i = 0; i < length; i++) { // 生成单向不循环链表
        insertNode(p, i + 1);
    }
    
    printf("original list:\n");
    printList(list);
    printf("\n");
    ListNode *result = reverseListFunc(p);
    printf("after reverse list:\n");
    printList(result);
    printf("\n");
}
