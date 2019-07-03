//
//  merge-arrays.swift
//  algorithm
//
//  Created by Kai on 2019/7/3.
//  Copyright © 2019 kai. All rights reserved.
//

import Foundation

/*
 URL Encode：字符串中的空格替换成 %20
 分析：连续内存中插入元素，会导致后续元素后移，这种情况考虑，从后往前插入。
 */
func replaceWhiteSpace(_ string: String) -> String {
//    guard string.isEmpty == false else { return string }
    var result: String
    var whiteSpaceCount: Int
    
    // 遍历原数组，确定需要替换的元素数量
    whiteSpaceCount = 0
    string.forEach { $0.asciiValue == 32 ? whiteSpaceCount += 1 : () }
    
    print("whiteSpaceCount=\(whiteSpaceCount)")
    
    let resultLength: Int
    resultLength = string.count + whiteSpaceCount * 2
    
    let pointer = UnsafeMutablePointer<CChar>.allocate(capacity: resultLength)
    pointer.initialize(repeating: 0, count: resultLength)
    
    let pointerOriginal = UnsafeMutablePointer<String>.allocate(capacity: string.count)
    var mutableStr = string
    pointerOriginal.initialize(from: &mutableStr, count: string.count)
    
    (0..<resultLength).reversed().forEach { (idx) in
        
    }
    
    
    result = ""
    
    return result
}
