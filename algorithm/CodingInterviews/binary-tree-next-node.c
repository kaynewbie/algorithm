//
//  binary-tree-next-node.c
//  algorithm
//
//  Created by Kai on 2019/7/7.
//  Copyright © 2019 kai. All rights reserved.
//

#include "binary-tree-next-node.h"
#include "stdlib.h"

TripleDirectionNode *createTree() {
    int size = sizeof(TripleDirectionNode);
    
    TripleDirectionNode *node1 = (TripleDirectionNode *)malloc(size);
    node1->value = 1;
    TripleDirectionNode *node2 = (TripleDirectionNode *)malloc(size);
    node2->value = 2;
    TripleDirectionNode *node3 = (TripleDirectionNode *)malloc(size);
    node3->value = 3;
    TripleDirectionNode *node4 = (TripleDirectionNode *)malloc(size);
    node4->value = 4;
    TripleDirectionNode *node5 = (TripleDirectionNode *)malloc(size);
    node5->value = 5;
    TripleDirectionNode *node6 = (TripleDirectionNode *)malloc(size);
    node6->value = 6;
    TripleDirectionNode *node7 = (TripleDirectionNode *)malloc(size);
    node7->value = 10;
    TripleDirectionNode *node8 = (TripleDirectionNode *)malloc(size);
    node8->value = 11;
    TripleDirectionNode *node9 = (TripleDirectionNode *)malloc(size);
    node9->value = 12;
    
    node6->left = node4;
    node6->right = node5;
    
    node4->parent = node6;
    node4->left = node3;
    node4->right = node7;
    
    node5->parent = node6;
    node5->left = node1;
    node5->right = node2;
    node3->parent = node4;
    node3->left = NULL;
    node3->right = NULL;
    node2->parent = node5;
    node2->left = node8;
    node2->right = NULL;
    node1->parent = node5;
    node1->left = NULL;
    node1->right = NULL;
    node7->parent = node4;
    node7->left = NULL;
    node7->right = NULL;
    node8->parent = node2;
    node8->left = node9;
    node8->right = NULL;
    node9->parent = node8;
    node9->left = NULL;
    node9->right = NULL;
    
    return node6;
}

/**
 分析：中序遍历下一个节点，两种情况：当前节点是父节点的左子节点/右子节点。
 左子节点：首先判断右子节点是否存在，是，则查找右子节点的最左子节点；否，则是父节点。
 右子节点：首先判断右子节点是否存在，是，则查找右子节点的最左子节点；否，则为空。
 */
TripleDirectionNode *nextNodeInOrder(TripleDirectionNode *tree) {
    if (tree == NULL) {
        return NULL;
    }
    if (tree->right == NULL) {
        if (tree->parent == NULL) {
            return NULL;
        } else if (tree->parent->left == tree) {
            return tree->parent;
        } else {
            return NULL;
        }
        return tree->parent;
    }
    tree = tree->right;
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}

void testNextNodeInOrder(void) {
    TripleDirectionNode *tree = createTree();
    TripleDirectionNode *current = tree->right->right;
    TripleDirectionNode *nextNode = nextNodeInOrder(current);
    if (nextNode) {
        printf("nextNode->value=%d", nextNode->value);
    } else {
        printf("current node is the last");
    }
}
