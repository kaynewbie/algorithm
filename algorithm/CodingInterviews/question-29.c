//
//  question-29.c
//  algorithm
//
//  Created by Kai on 2019/8/4.
//  Copyright © 2019 kai. All rights reserved.
//

#include "question-29.h"

/*
 顺时针打印矩阵
 */

void printMatrixInZCircle(int *, int, int, int);

void printMatrixClockwisely(int *matrix, int rows, int columns) {
    if (matrix == NULL) return;
    
    int start = 0;
    while (rows > start * 2 && columns > start * 2) {
        printMatrixInZCircle(matrix, rows, columns, start);
        
        start++;
    }
}

void printMatrixInZCircle(int *matrix, int rows, int columns, int start) {
    int endX = columns - start - 1;
    int endY = rows - start - 1;
    
    // 从左往右
    for (int i = start; i <= endX; i++) {
        printf("%d ", matrix[start * columns + i]);
    }
    
    // 从上往下
    for (int i = start + 1; i <= endY; i++) {
        printf("%d ", matrix[i * columns + endX]);
    }
    
    // 从右往左
    for (int i = endX - 1; i >= start; i--) {
        printf("%d ", matrix[endY * columns + i]);
    }
    
    // 从下往上
    for (int i = endY - 1; i >= start + 1; i--) {
        printf("%d ", matrix[i * columns + start]);
    }
}

void testPrintMatrixClockwisely1(void) {
    const int length = 16;
    int matrix[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    printf("matrix closewisely: ");
    printMatrixClockwisely(matrix, 4, 4);
    printf("\n");
}

void testPrintMatrixClockwisely2(void) {
    const int length = 1;
    int matrix[length] = {1};
    printf("matrix closewisely: ");
    printMatrixClockwisely(matrix, 1, 1);
    printf("\n");
}

void testPrintMatrixClockwisely(void) {
    testPrintMatrixClockwisely1();
    testPrintMatrixClockwisely2();
}
