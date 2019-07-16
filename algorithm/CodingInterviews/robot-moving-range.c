//
//  robot-moving-range.c
//  algorithm
//
//  Created by Kai on 2019/7/16.
//  Copyright © 2019 kai. All rights reserved.
//

#include "robot-moving-range.h"
#include "stdbool.h"
#include "string.h"

int digitalNumber(int value);
void movingCountCore(int treshold, int rows, int cols,
                     int row, int col, int *count, bool *visited);

/*
 机器人移动范围
 rows * cols 的矩阵，机器人从坐标(0, 0)出发，每次只能往上、下、左、右方向移动一格，
 能够进入的格子要求位置的索引数位之和小于 treshold 值，且到达过的格子不能再进入。
 问能移动多少格子。
 */
int movingCount(int treshold, int rows, int cols) {
    int count = 0;
    bool visited[rows * cols];
    memset(visited, 0, sizeof(bool) * rows * cols);
    
    movingCountCore(treshold, rows, cols, 0, 0, &count, visited);
    return count;
}

void movingCountCore(int treshold, int rows, int cols, int row,
                     int col, int *count, bool *visited)
{
    int sum = digitalNumber(row) + digitalNumber(col);
    bool inMatrix = row >= 0 && row < rows && col >= 0 && col < cols;
    if (sum <= treshold && inMatrix && !visited[row * cols + col]) {
        visited[row * cols + col] = true;
        (*count)++;
        
        movingCountCore(treshold, rows, cols, row, col - 1, count, visited);
        movingCountCore(treshold, rows, cols, row + 1, col, count, visited);
        movingCountCore(treshold, rows, cols, row, col + 1, count, visited);
        movingCountCore(treshold, rows, cols, row - 1, col, count, visited);
    }
}

int digitalNumber(int value) {
    if (value <= 0) {
        return 0;
    }
    int remainder;
    int result = 0;
    do {
        remainder = value % 10;
        result += remainder;
        value /= 10;
    } while (value > 0);
    return result;
}

/**
 matrix=0 * 0，k=0
 */
void testMovingCount1() {
    int result;
    int rows = 0, cols = 0, treshold = 0;
    char *format = "rows: %d, cols: %d, treshold: %d, result=%d\n";
    result = movingCount(treshold, rows, cols);
    printf(format, rows, cols, treshold, result);
}

/**
 matrix=1 * 1，k=1
 */
void testMovingCount2() {
    int result;
    int rows = 1, cols = 1, treshold = 1;
    char *format = "rows: %d, cols: %d, treshold: %d, result=%d\n";
    result = movingCount(treshold, rows, cols);
    printf(format, rows, cols, treshold, result);
}

/**
 matrix=2 * 2, k = 2
 */
void testMovingCount3() {
    int result;
    int rows = 2, cols = 2, treshold = 2;
    char *format = "rows: %d, cols: %d, treshold: %d, result=%d\n";
    result = movingCount(treshold, rows, cols);
    printf(format, rows, cols, treshold, result);
}

/**
 matrix=10 * 20, k = 10
 */
void testMovingCount4() {
    int result;
    int rows = 10, cols = 20, treshold = 10;
    char *format = "rows: %d, cols: %d, treshold: %d, result=%d\n";
    result = movingCount(treshold, rows, cols);
    printf(format, rows, cols, treshold, result);
}

/**
 value=0
 */
void testDigitalNumber1() {
    int x = 0;
    int result = digitalNumber(x);
    printf("value %d digital number = %d\n", x, result);
}

/**
 value=123
 */
void testDigitalNumber2() {
    int x = 123;
    int result = digitalNumber(x);
    printf("value %d digital number = %d\n", x, result);
}

/**
 value=100
 */
void testDigitalNumber3() {
    int x = 100;
    int result = digitalNumber(x);
    printf("value %d digital number = %d\n", x, result);
}

/**
 value=-1
 */
void testDigitalNumber4() {
    int x = -1;
    int result = digitalNumber(x);
    printf("value %d digital number = %d\n", x, result);
}

void testRobotMovingRange(void) {
    testDigitalNumber1();
    testDigitalNumber2();
    testDigitalNumber3();
    testDigitalNumber4();
    printf("\n");
    testMovingCount1();
    testMovingCount2();
    testMovingCount3();
    testMovingCount4();
}
