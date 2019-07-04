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

/*
 三种遍历方式：前序(preOrder)、中序(inOrder)、后序(postOrder)
 两种实现方式：循环(cycle)、递归(recursive)
 */

/**
 创建二叉树。
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
    
    node6->leftChild = node4;
    node6->rightChild = node5;
    
    node4->leftChild = node3;
    node4->rightChild = NULL;
    
    node5->leftChild = node1;
    node5->rightChild = node2;
    node3->leftChild = NULL;
    node3->rightChild = NULL;
    node2->leftChild = NULL;
    node2->rightChild = NULL;
    node1->leftChild = NULL;
    node1->rightChild = NULL;
    
    return node6;
}

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
        6
    4       5
 3         1 2
 
 预期输出：6 4 3 5 1 2
 */
void testPreOrderCycle(void) {
    Node *tree = createBinaryTree();
    
    preOrderCycle(tree);
}

/**
 循环实现中序遍历
 
 分析：左子节点->根节点->右子节点
 */
void inOrderCycle(Node *tree) {
    
}

