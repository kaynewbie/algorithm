//
//  question-33.h
//  algorithm
//
//  Created by Kai on 2019/8/24.
//  Copyright © 2019 kai. All rights reserved.
//

#ifndef question_33_h
#define question_33_h

/*
 判断一个序列是否二叉搜索树(BST)的后序遍历
 */

#include <stdio.h>
#include <stdbool.h>

bool isPostOrderOfBST(int *sequence, int len);

// MARK:- 测试

void testIsPostOrderOfBST(void);

#endif /* question_33_h */
