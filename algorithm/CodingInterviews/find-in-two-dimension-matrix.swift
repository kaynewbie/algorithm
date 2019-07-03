//
//  find-in-two-dimension-matrix.swift
//  algorithm
//
//  Created by Kai on 2019/7/2.
//  Copyright © 2019 kai. All rights reserved.
//

import Foundation

/*
 一个整型二维矩阵，行列数值从左上角往右下角递增，给定一个数，找出他在矩阵中的位置。
 分析：确定一个维度，再往另一个维度查找。
 给定3x3矩阵，选定从左下角开始，N22 是第三行的最小值，如果给定值大于 N22，再往第三行着；否则，往上一行找，以此类推
 */
func findValue(_ target: Int, in matrix: [[Int]]) -> (Int, Int)? {
    let length: Int
    var result: (Int, Int)?
    var row: Int
    var column: Int
    
    length = matrix.count
    row = length - 1
    column = 0
    
    while row >= 0, column <= length - 1 {
        let currentRow: [Int]
        currentRow = matrix[row]
        guard currentRow.count == length else { break }
        
        if currentRow[column] == target {
            result = (row, column)
            break
        } else if currentRow[column] < target {//列增加
            column += 1
        } else {//行减小
            row -= 1
        }
    }
    
    return result
}
