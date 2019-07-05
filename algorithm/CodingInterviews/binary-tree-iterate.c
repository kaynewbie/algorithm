//
//  binary-tree-iterate.c
//  algorithm
//
//  Created by Kai on 2019/7/4.
//  Copyright © 2019 kai. All rights reserved.
//

#include "binary-tree-iterate.h"
#include "stack.h"
#include "stdlib.h"
#include "string.h"

/*
 三种遍历方式：前序(preOrder)、中序(inOrder)、后序(postOrder)
 两种实现方式：循环(cycle)、递归(recursive)
 */

/**
 创建二叉树。
 
            6
    4           5
 3     10     1   2
 */
Node *createBinaryTree(void) {
    int size = sizeof(Node);
    
    Node *node1 = (Node *)malloc(size);
    node1->value = 1;
    Node *node2 = (Node *)malloc(size);
    node2->value = 2;
    Node *node3 = (Node *)malloc(size);
    node3->value = 3;
    Node *node4 = (Node *)malloc(size);
    node4->value = 4;
    Node *node5 = (Node *)malloc(size);
    node5->value = 5;
    Node *node6 = (Node *)malloc(size);
    node6->value = 6;
    Node *node7 = (Node *)malloc(size);
    node7->value = 10;
    
    node6->leftChild = node4;
    node6->rightChild = node5;
    
    node4->leftChild = node3;
    node4->rightChild = node7;
    
    node5->leftChild = node1;
    node5->rightChild = node2;
    node3->leftChild = NULL;
    node3->rightChild = NULL;
    node2->leftChild = NULL;
    node2->rightChild = NULL;
    node1->leftChild = NULL;
    node1->rightChild = NULL;
    node7->leftChild = NULL;
    node7->rightChild = NULL;
    
    return node6;
}

// MARK: - 循环实现前序遍历
/**
 循环实现前序遍历。
 
 分析：根节点->左子节点->右子节点
 因为需要逆向访问右子节点，所以需要借助栈记录未访问右子节点的节点。
 */
void preOrderCycle(Node *tree) {
    // 栈存指针而不是结构体
    int size = sizeof(Node *);
    Stack *stack = createStack(10, size);
    
    Node *current = tree;
    const char *format = "%d ";
    while (current != NULL || stack->top >= 0) {
        if (current != NULL) {
            printf(format, current->value);
            stackPush(stack, (void *)&current);
            current = current->leftChild;
        } else {
            stackPop(stack, (void *)&current);
            current = current->rightChild;
        }
    }
}

/**
 预期输出：6 4 3 10 5 1 2
 */
void testPreOrderCycle(void) {
    Node *tree = createBinaryTree();
    preOrderCycle(tree);
}

// MARK: - 循环实现中序遍历
/**
 循环实现中序遍历
 
 分析：左子节点->根节点->右子节点
 */
void inOrderCycle(Node *tree) {
    int size = sizeof(Node);
    Stack *s = createStack(10, size);
    
    Node *current = tree;
    char *format = "%d ";
    while (current != NULL || s->top >= 0) {
        if (current) {
            stackPush(s, current);
            current = current->leftChild;
        } else {
            stackPop(s, current);
            printf(format, current->value);
            current = current->rightChild;
        }
    }
}

/**
 预期输出：3 4 10 6 1 5 2
 */
void testInOrderCycle() {
    Node *tree = createBinaryTree();
    inOrderCycle(tree);
}

// MARK:- 循环实现后序遍历

/**
 左子节点->右子节点->父节点
 父节点和右子节点都要入栈，分别入栈/出栈两次。
 */
void postOrderCycle(Node *tree) {
    Stack *s = createStack(10, sizeof(Node *));
    Node *current = tree;

    do {
        while (current) {
            if (current->rightChild) {
                stackPush(s, &(current->rightChild));
            }
            stackPush(s, &current);
            current = current->leftChild;
        }
        stackPop(s, (Node *)&current);
        printf("\ncurrent value1=%d\n", current->value);
        Node *top = tree;
        stackTop(s, (Node *)&top);
        if (current->rightChild && top == current->rightChild) {
            Node *tmp = NULL;
            // 弹出右子节点
            stackPop(s, (Node *)&tmp);
            stackPush(s, &current);
            current = current->rightChild;
        } else {
            printf("%d ", current->value);
            current = NULL;
        }
    } while (s->top >= 0);
}
// 预期输出：3 10 4 1 2 5 6
void testPostOrderCycle() {
    Node *tree = createBinaryTree();
    postOrderCycle(tree);
}

void testMemcpy() {
    const char src[50] = "http://www.tutorialspoint.com";
    char dest[50];
    memcpy(dest, src, strlen(src)+1);
    printf("After memcpy dest = %s\n", dest);
}
