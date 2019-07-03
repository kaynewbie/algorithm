//
//  any-repeat-number-in-array.swift
//  algorithm
//
//  Created by Kai on 2019/6/30.
//  Copyright © 2019 kai. All rights reserved.
//

import Foundation

/*
 * n 位数组，值大小为 0~n-1，取出任意重复数字。
 * 如，[1, 2, 3, 3, 2]，则，取出 2 或者 3。
 **/
/*
 解：遍历数组，判断：索引 i 上的元素值 m 是否满足，i == m，
        是：继续遍历，否：索引 m 上的元素值 x 是否满足 m == x，
        是：m 是重复元素值，否：交换 array[i] 和 array[m]。
 时间复杂度：O(n)，空间复杂度：O(1)
 */

enum CustomError: Error {
    case outOfIndex
}

func anyRepeatValue(in array: inout [Int]) throws -> Int? {
    for idx in 0..<array.count {
        var m: Int
        
        m = array[idx]
        while m != idx {
            guard m < array.count else {
                throw CustomError.outOfIndex
            }
            let valueAtM = array[m]
            
            if valueAtM == m {// 发现重复元素
                return m
            } else {// 交换两个元素
                array[idx] = valueAtM
                array[m] = m
                m = valueAtM
            }
        }
    }
    return nil
}

/*
 n+1位的数组，数组元素 1~n，找出任意重复元素，不能修改输入数组
 分析：至少一个元素重复
 1~n 用中间值 m 分为两段，1~m, m+1~n，指定范围大小内的数值数量如果大于该范围大小，则此范围内存在重复数值，循环二分查找。
 1～9号水桶，对应数值放入对应水桶。现在水桶分成两部分确定元素，1～5 和 5～9，遍历数组，如果1～5号桶元素大于5则存在重复，1～5继续二分查找。
 */

func countRange(in array: [Int], start: Int, end: Int) -> Int {
    var count: Int = 0
    array.forEach { (value) in
        if value >= start && value <= end {
            count += 1
        }
    }
    return count
}

/// 时间复杂度：O(nlogn)，空间复杂度：O(1)
func anyRepeatValue(in array: [Int]) -> Int? {
    var start: Int
    var end: Int
    var mid: Int
    
    start = 1
    end = array.count - 1
    
    while start <= end {
        mid = (start + end) >> 1
        
        let tmp = countRange(in: array, start: start, end: mid)
        if tmp > (mid - start + 1) {// 重复元素在当前这段
            end = mid
        } else {// 重复元素在另一段
            start = mid + 1
        }
        if start == end {
            return start
        }
    }
    
    return nil
}
