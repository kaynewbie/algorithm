//
//  question-33.c
//  algorithm
//
//  Created by Kai on 2019/8/24.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-33.h"

bool portion(int *sequence, int start, int end);

/**
 序列最后一个节点是 BST 的根节点，遍历序列，前面部分小于根节点的是左子树，后面大于根节点的是右子树。
 不断二分并递推

 @param sequence 待检索序列
 @param len 序列长度
 @return 是否能表示一颗 BST 的后续遍历
 */
bool isPostOrderOfBST(int *sequence, int len) {
    if (sequence == NULL || len <= 0) return false;
    
    return portion(sequence, 0, len - 1);
}

// MARK:- 辅助函数

#define MAX(x, y) ((x < y) ? y : x)

bool portion(int *sequence, int start, int end) {
    if (start == end) return true;
    
    int idx;
    int mid;
    
    idx = start;
    while ((idx < end) && (sequence[idx] < sequence[end])) {
        idx++;
    }
    mid = idx;
    while ((idx < end) && (sequence[idx] > sequence[end])) {
        idx++;
    }
    if (idx < end) return false;
    return portion(sequence, start, MAX(start, mid - 1))
    && portion(sequence, mid, MAX(mid, end - 1));
}

// MARK:- 测试

void testIsPostOrderOfBST1(void) {
    const int len = 7;
    int nums[len] = {5, 7, 6, 9, 11, 10, 8};
    bool result = isPostOrderOfBST(nums, len);
    printf("%s %s post order of a BST.\n", __func__, result ? "IS" : "IS NOT");
}

void testIsPostOrderOfBST2(void) {
    const int len = 9;
    int nums[len] = {75, 70, 80, 95, 90, 130, 180, 150, 100};
    bool result = isPostOrderOfBST(nums, len);
    printf("%s %s post order of a BST.\n", __func__, result ? "IS" : "IS NOT");
}

void testIsPostOrderOfBST3(void) {
    const int len = 1;
    int nums[len] = {23};
    bool result = isPostOrderOfBST(nums, len);
    printf("%s %s post order of a BST.\n", __func__, result ? "IS" : "IS NOT");
}

void testIsPostOrderOfBST4(void) {
    const int len = 3;
    int nums[len] = {1, 3, 2};
    bool result = isPostOrderOfBST(nums, len);
    printf("%s %s post order of a BST.\n", __func__, result ? "IS" : "IS NOT");
}

void testIsPostOrderOfBST5(void) {
    const int len = 9;
    int nums[len] = {75, 70, 80, 95, 90, 130, 60, 150, 100};
    bool result = isPostOrderOfBST(nums, len);
    printf("%s %s post order of a BST.\n", __func__, result ? "IS" : "IS NOT");
}

void testIsPostOrderOfBST6(void) {
    const int len = 3;
    int nums[len] = {1, 2, 3};
    bool result = isPostOrderOfBST(nums, len);
    printf("%s %s post order of a BST.\n", __func__, result ? "IS" : "IS NOT");
}

void testIsPostOrderOfBST7(void) {
    const int len = 7;
    int nums[len] = {1, 2, 10, 4, 5, 6, 7};
    bool result = isPostOrderOfBST(nums, len);
    printf("%s %s post order of a BST.\n", __func__, result ? "IS" : "IS NOT");
}

void testIsPostOrderOfBST(void) {
    testIsPostOrderOfBST1();
    testIsPostOrderOfBST2();
    testIsPostOrderOfBST3();
    testIsPostOrderOfBST4();
    testIsPostOrderOfBST5();
    testIsPostOrderOfBST6();
    testIsPostOrderOfBST7();
}
