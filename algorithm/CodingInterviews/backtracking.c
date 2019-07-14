//
//  backtracking.c
//  algorithm
//
//  Created by Kai on 2019/7/15.
//  Copyright © 2019 kai. All rights reserved.
//

#include "backtracking.h"
#include "stdbool.h"
#include "string.h"

bool hasPathCore(char *matrix, int rows, int cols, int row,
                 int col, const char *path, int pathLen, bool *visited);
bool hasPath(char *matrix, int rows, int cols, const char *path)
{
    if (matrix == NULL || path == NULL) {
        return false;
    }
    // 矩阵元素访问情况，初始都是 false，访问过后改为 true。
    bool visited[rows * cols];
    int pathLen = 0;
    memset(visited, 0, rows * cols);
    for (int i = 0; i <rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (hasPathCore(matrix, rows, cols, i, j, path, pathLen, visited)) {
                return true;
            }
        }
    }
    return false;
}

/**
 访问一个元素的操作。

 @param matrix 地图矩阵
 @param rows 矩阵总行数
 @param cols 矩阵总列数
 @param row 当前元素行数
 @param col 当前元素列数
 @param path 需要寻找到的路径
 @param pathLen 当前寻找路径的长度
 @param visited 地图矩阵对应的每个元素访问情况
 @return 当前元素是否匹配
 */
bool hasPathCore(char *matrix, int rows, int cols, int row,
                 int col, const char *path, int pathLen, bool *visited)
{
    if (matrix == NULL || path == NULL) {
        return false;
    }
    if (path[pathLen] == '\0') {
        return true;
    }
    
    bool hasPath = false;
    bool inMatrix = row >= 0 && row <= rows && col >= 0 && col <= cols;
    while (inMatrix && !visited[row * cols + col] && matrix[row * cols + col] == path[pathLen]) {
        pathLen++;
        printf("current visit ele: %d, path length: %d\n", row * cols + col, pathLen);
        visited[row * cols + col] = true;
        hasPath = hasPathCore(matrix, rows, cols, row, col - 1, path, pathLen, visited)
        || hasPathCore(matrix, rows, cols, row - 1, col, path, pathLen, visited)
        || hasPathCore(matrix, rows, cols, row + 1, col, path, pathLen, visited)
        || hasPathCore(matrix, rows, cols, row, col + 1, path, pathLen, visited);
    }
    return hasPath;
}


/**
 如下矩阵中查找路径 abfj
 a b c d
 e f j h
 i j k l
 */
void testBacktracking(void) {
    int length = 0;
    char matrix[] = "abcdefjhijkl";
    char *p = matrix;
    while (*(p + length) != '\0') {
        length++;
    }
    char *path = "abfjh";
    bool result = hasPath(matrix, 3, 4, path);
    printf("Backtracking result=%d\n", result);
}
