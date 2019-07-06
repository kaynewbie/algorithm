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
    node1->_id = (int)node1;
    Node *node2 = (Node *)malloc(size);
    node2->value = 2;
    node2->_id = (int)node2;
    Node *node3 = (Node *)malloc(size);
    node3->value = 3;
    node3->_id = (int)node3;
    Node *node4 = (Node *)malloc(size);
    node4->value = 4;
    node4->_id = (int)node4;
    Node *node5 = (Node *)malloc(size);
    node5->value = 5;
    node5->_id = (int)node5;
    Node *node6 = (Node *)malloc(size);
    node6->value = 6;
    node6->_id = (int)node6;
    Node *node7 = (Node *)malloc(size);
    node7->value = 10;
    node7->_id = (int)node7;
    
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

// MARK:- 循环
// MARK: - 循环实现前序遍历
/**
 循环实现前序遍历。
 
 分析：根节点->左子节点->右子节点
 因为需要逆向访问右子节点，所以需要借助栈记录未访问右子节点的节点。
 */
void preOrderCycle(Node *tree) {
    // 栈存结构体
    int size = sizeof(Node);
    Stack *stack = createStack(size, 10);
    
    Node *current = tree;
    const char *format = "%d ";
    printf("循环打印二叉树先序遍历: ");
    while (current != NULL || stack->top >= 0) {
        if (current != NULL) {
            printf(format, current->value);
            stackPush(stack, current);
            current = current->leftChild;
        } else {
            Node *temp = (Node *)malloc(sizeof(Node));
            stackPop(stack, temp);
            current = temp->rightChild;
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
    Stack *s = createStack(size, 10);
    
    Node *current = tree;
    char *format = "%d ";
    printf("循环打印二叉树中序遍历: ");
    while (current != NULL || s->top >= 0) {
        if (current) {
            stackPush(s, current);
            current = current->leftChild;
        } else {
            Node *temp = (Node *)malloc(sizeof(Node));
            stackPop(s, temp);
            printf(format, temp->value);
            current = temp->rightChild;
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
    Stack *s = createStack(sizeof(Node), 10);
    Node *current = tree;

    printf("循环打印二叉树后序遍历: ");
    do {
        while (current) {
            if (current->rightChild) {
                stackPush(s, current->rightChild);
            }
            stackPush(s, current);
            current = current->leftChild;
        }
        Node *temp = (Node *)malloc(sizeof(Node));
        stackPop(s, temp);
        current = temp;
        
        Node *top = (Node *)malloc(sizeof(Node));
        stackTop(s, top);
        /*
          必须要判断 top == current->rightChild，因为回溯时，
         根据栈内是否存在当前节点的右子节点判断，此右子节点是否访问过。
         
         问题：当前栈的实现，pop 时，要重新开辟内存用于写入 pop 出的数据，
         导致无法通过地址判断树中节点和 pop 出的节点是否同一节点。
         解决：
            方法一、节点数据结构增加唯一标识；
            方法二、栈实现时，元素类型用节点地址而不是拷贝数据。
         */
        if (current->rightChild && top->_id == current->rightChild->_id) {
            Node *temp = (Node *)malloc(sizeof(Node));
            stackPop(s, temp);
            
            stackPush(s, current);
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

// MARK:- 递归
// MARK:- 递归实现前序遍历
void preOrderRecursive(Node *tree) {
    if (tree == NULL) {
        return;
    }
    char *format = "%d ";
    printf(format, tree->value);
    preOrderRecursive(tree->leftChild);
    preOrderRecursive(tree->rightChild);
}
void testPreOrderRecursive() {
    Node *tree = createBinaryTree();
    printf("递归打印二叉树前序遍历: ");
    preOrderRecursive(tree);
}

// MARK:- 递归实现中序遍历
void inOrderRecursive(Node *tree) {
    if (tree == NULL) {
        return;
    }
    char *format = "%d ";
    inOrderRecursive(tree->leftChild);
    printf(format, tree->value);
    inOrderRecursive(tree->rightChild);
}
void testInOrderRecursive() {
    Node *tree = createBinaryTree();
    printf("递归打印二叉树中序遍历: ");
    inOrderRecursive(tree);
}

// MARK:- 递归实现后序遍历
void postOrderRecursive(Node *tree) {
    if (tree == NULL) {
        return;
    }
    char *format = "%d ";
    postOrderRecursive(tree->leftChild);
    postOrderRecursive(tree->rightChild);
    printf(format, tree->value);
}
void testPostOrderRecursive() {
    Node *tree = createBinaryTree();
    printf("递归打印二叉树后序遍历: ");
    postOrderRecursive(tree);
}
