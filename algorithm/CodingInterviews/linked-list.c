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

void testFormat1();
void testFormat2();
void testFormat3();
void testFormat4();
void testFormat5();
void testFormat6();

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
ListNode *insertNode(ListNode **p, int value) {
    if (p == NULL) {
        return NULL;
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
    return newNode;
}

ListNode *findLast(ListNode *list) {
    if (list == NULL) {
        return NULL;
    }
    while (list->next) {
        list = list->next;
    }
    return list;
}

/// 找到队尾节点并删除
/// @param list 单向链表
//ListNode *findAndRemoveLast(ListNode *list) {
//    if (list == NULL) {
//        return NULL;
//    }
//
//    return NULL;
//}

/// 从单向链表中，寻找目标节点的前一个节点。如果目标节点是第一个，则返回空。
/// @param list 单向链表
/// @param target 链表中的指定节点
ListNode *findPreviousNodeOfTarget(ListNode *list, ListNode *target) {
    if (list == NULL) {
        return NULL;
    }
    ListNode *previous;
    ListNode *current;
    previous = NULL;
    current = list;
    
    if (target == NULL) {
        return findLast(list);
    }
    
    while (current->next && current != target) {
        previous = current;
        current = current->next;
    }
    
    return previous;
}

/// 单向链表重新排序
/// 给定 L0->L1->L2->...->Ln-1->Ln，将其重新排列为L0->Ln->L1->Ln-1->L2->Ln-2...
/// 解法如下：时间复杂度 O(n^2)，空间复杂度 O(n)
ListNode *formatList(ListNode *list) {
    ListNode *result = NULL;
    
    ListNode *currentList;
    ListNode *head;
    ListNode *tail;
    currentList = list;
    tail = NULL;
    
    /// 循环获取链表第一个和最后一个节点，两个节点往中间逼近，直到相遇
    while (currentList && currentList != tail) {
        /// 获取头节点，插入到新链表的末尾
        head = currentList;
        insertNode(&result, head->value);
        /// currentList 往后移动
        currentList = currentList->next;
        if (currentList == NULL) {
            break;
        }
        /// 获取尾节点，插入到新链表的末尾
        tail = findPreviousNodeOfTarget(currentList, tail);
        if (tail == NULL) {
            break;
        }
        insertNode(&result, tail->value);
    }
    
    return result;
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
    testFormat1();
    testFormat2();
    testFormat3();
    testFormat4();
    testFormat5();
    testFormat6();
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

//MARK:- O(1)复杂度删除节点
void deleteNode(ListNode **list, ListNode *node) {
    if (list == NULL || *list == NULL || node == NULL) {
        return;
    }
    if (node->next == NULL) {
        removeNode(list, node->value);
    } else {
        ListNode *nextNode = node->next;
        node->value = nextNode->value;
        node->next = nextNode->next;
        free(nextNode);
        nextNode = NULL;
    }
}

/**
 list: NULL
 delete: NULL
 result: NULL
 */
void testDeleteNode1() {
    ListNode *list = NULL;
    ListNode **p = &list;
    deleteNode(p, NULL);
    printList(list);
}

/**
 list: 23 -> NULL
 delete: 23
 result: NULL
 */
void testDeleteNode2() {
    ListNode *list = NULL;
    ListNode **p = &list;
    ListNode *inserted = insertNode(p, 23);
    deleteNode(p, inserted);
    printList(list);
}

/**
 list: 23 -> 24 -> NULL
 delete: 23
 result: 24 -> NULL
 */
void testDeleteNode3() {
    ListNode *list = NULL;
    ListNode **p = &list;
    ListNode *inserted23 = insertNode(p, 23);
    insertNode(p, 24);
    deleteNode(p, inserted23);
    printList(list);
}

/**
 list: 23 -> 24 -> 6 -> NULL
 delete: 6
 result: 23 -> 24 -> NULL
 */
void testDeleteNode4() {
    ListNode *list = NULL;
    ListNode **p = &list;
    insertNode(p, 23);
    insertNode(p, 24);
    ListNode *inserted6 = insertNode(p, 6);
    deleteNode(p, inserted6);
    printList(list);
}

void testDeleteNode(void) {
    testDeleteNode1();
    testDeleteNode2();
    testDeleteNode3();
    testDeleteNode4();
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

#pragma mark - 单向链表按照指定规则重排

void testFormat1() {
    printf("--------- begin test -------------\n");

    ListNode *list = NULL;
    ListNode **p = &list;
    
    insertNode(p, 1);
    insertNode(p, 2);
    insertNode(p, 3);
    insertNode(p, 4);
    
    printList(list);
    
    printf("--------- after format -------------\n");
    
    list = formatList(list);
    
    printList(list);
    
    printf("--------- end test -------------\n");
}

/// 1 7 2 6 3 5 4
void testFormat2() {
    printf("--------- begin test -------------\n");

    ListNode *list = NULL;
    ListNode **p = &list;
    
    insertNode(p, 1);
    insertNode(p, 2);
    insertNode(p, 3);
    insertNode(p, 4);
    insertNode(p, 5);
    insertNode(p, 6);
    insertNode(p, 7);
    
    printList(list);
    
    printf("--------- after format -------------\n");
    
    list = formatList(list);
    
    printList(list);
    printf("--------- end test -------------\n");

}

/// 1
void testFormat3() {
    printf("--------- begin test -------------\n");
    
    ListNode *list = NULL;
    ListNode **p = &list;
    
    insertNode(p, 1);
    
    printList(list);
    
    printf("--------- after format -------------\n");
    
    list = formatList(list);
    
    printList(list);
    printf("--------- end test -------------\n");
}

/// null
void testFormat4() {
    printf("--------- begin test -------------\n");
    
    ListNode *list = NULL;
//    ListNode **p = &list;
    
//    insertNode(p, 1);
    
    printList(list);
    
    printf("--------- after format -------------\n");
    
//    list = formatList(list);
    
    printList(list);
    
    printf("--------- end test -------------\n");
}

void testFormat5() {
    printf("--------- begin test -------------\n");

    ListNode *list = NULL;
    ListNode **p = &list;
    
    insertNode(p, 1);
    insertNode(p, 2);
    insertNode(p, 3);
    insertNode(p, 4);
    insertNode(p, 5);
    insertNode(p, 6);
    insertNode(p, 7);
    insertNode(p, 8);
    insertNode(p, 9);
    insertNode(p, 10);
    insertNode(p, 11);
    insertNode(p, 12);
    insertNode(p, 13);
    insertNode(p, 14);
    
    printList(list);
    
    printf("--------- after format -------------\n");
    
    list = formatList(list);
    
    printList(list);
    printf("--------- end test -------------\n");

}

void testFormat6() {
    printf("--------- begin test -------------\n");

    ListNode *list = NULL;
    ListNode **p = &list;
    
    insertNode(p, 1);
    insertNode(p, 2);
    insertNode(p, 3);
    insertNode(p, 4);
    insertNode(p, 3);
    insertNode(p, 2);
    insertNode(p, 1);
    
    printList(list);
    
    printf("--------- after format -------------\n");
    
    list = formatList(list);
    
    printList(list);
    printf("--------- end test -------------\n");

}
