//
//  maximum-depth-of-binary-tree.c
//  algorithm
//
//  Created by Kai on 2019/7/30.
//  Copyright © 2019 kai. All rights reserved.
//

#include "maximum-depth-of-binary-tree.h"
#include "binary-tree.h"

#define MAX(x, y) ((x > y) ? x : y)
int depthInTree(TreeNode *tree, int depth);

int maxDepth(struct TreeNode* root){
    return depthInTree(root, 0);
}

int depthInTree(TreeNode *tree, int depth) {
    if (tree == NULL) {
        return depth;
    }
    depth++;
    int depthLeft = depthInTree(tree->left, depth);
    int depthRight = depthInTree(tree->right, depth);
    return MAX(depthLeft, depthRight);
}

/*
 [3,9,20,null,null,15,7]
 */
void testMaxDepthInTree1(void) {
    const int length = 7;
    int array[length] = {3,9,20,0,0,15,7};
    TreeNode *tree = createBinaryTree(array, length);
    int result = maxDepth(tree);
    printf("tree: ");
    preOrderRecursive(tree);
    printf("\n");
    printf("max depth = %d\n", result);
}

void testMaxDepthInTree(void) {
    testMaxDepthInTree1();
}
