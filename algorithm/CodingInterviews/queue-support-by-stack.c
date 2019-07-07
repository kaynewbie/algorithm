//
//  queue-support-by-stack.c
//  algorithm
//
//  Created by Kai on 2019/7/7.
//  Copyright © 2019 kai. All rights reserved.
//

#include "queue-support-by-stack.h"

/*
 分析：两个栈，栈1作为主栈，入队的时候往栈1执行 push 操作；栈2作为临时内存，出队时栈1数据逐个 pop 并 push 到栈2。根据下一次操作再决定把数据保留在栈2还是回推到栈1。
 */
