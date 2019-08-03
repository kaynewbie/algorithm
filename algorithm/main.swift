//
//  main.swift
//  algorithm
//
//  Created by Kai on 2019/6/30.
//  Copyright © 2019 kai. All rights reserved.
//

import Foundation

let group = DispatchGroup()
let concurrencyQueue = DispatchQueue(label: "com.test.concurrent", attributes: .concurrent)


/// 多线程环境测试单例
func testSingleton() {
    for idx in 0..<10 {
        group.enter()
        concurrencyQueue.async {
            print("########## \(idx) ##########")
            let instance = Singleton.instance1()
            instance?.log()
            group.leave()
        }
    }
}

/// 测试数组任意重复值
func testRepeatValue() {
    var array = [0, 1, 10, 4, 3]
    do {
        if let value = try anyRepeatValue(in: &array) {
            print("repeat value = \(value)")
        } else {
            print("no repeat value")
        }
    } catch {
        print(error.localizedDescription)
    }
}

func testRepeatValue1() {
    let array = [1, 1]
    if let result = anyRepeatValue(in: array) {
        print("result=\(result)")
    } else {
        print("fail")
    }
}

/*
  -         -
 |  1, 6, 13  |
 |  2, 7, 15  |
 |  3, 9, 120  |
  -         -
 */
func testFindValueInTwoDimensionsMatrix() {
    let matrix = [[1, 6, 13], [2, 7, 15], [3, 9, 120]]
    let target = 14
    if let result = findValue(target, in: matrix) {
        print("result at row: \(result.0), column: \(result.1)")
    } else {
        print("fail")
    }
}

func testURLEncode() {
    testFunc()
}

func testListSwift() {
    testList()
}

//testSingleton()

//testRepeatValue()

//testRepeatValue1()

//testFindValueInTwoDimensionsMatrix()

//testURLEncode()

//testURLEncode()

//testListSwift()

//testPreOrderCycle()
//print("\n")
//testInOrderCycle()
//print("\n")
//testPostOrderCycle()
//print("\n")
//testPreOrderRecursive()
//print("\n")
//testInOrderRecursive()
//print("\n")
//testPostOrderRecursive()

//testRebuildBinaryTree()

//testNextNodeInOrder()

//testQueue()

//testFibonacciRecursive();

//testBinarySearch()

//testQuickSort()

//testreversedArray1()
//testreversedArray2()
//testreversedArray3()

//testLongestPalindromicSubstring()
//testLongestPalindromicSubstringByManacher()

//testBacktracking()

//testReverse()

//testIsPalindrome()

//testRobotMovingRange()

//testRomainToInt()

//testLongestCommonPrefix()

//testMaxProduct()

//testReverseSingleDirectionList()

//testCountOneInBinaryNum()

//testPower()

//testIncrement()
//testPrint1ToMaxOfN()

//testIsValid()

//testDeleteNode()

//testMatch()

//testIsNumeric()

//testReorderArray()

//testFindKthNodeFormTail()

//testMergeTwoLists()

//testRemoveDuplicates()

//testRemoveElement()

//testStrMethod1()
//testStrMethod2()
//testStrMethod3()

//testSearchInsert()

//testCountAnSay()

//testMaxSubarray()

//testLengthOfLastWord()

//testPlusOne()

//testAddBinary()

//testMySqrtMethod2()

//testClimbStairs()

//testRemoveDuplicatesinSortedList()

//testMergeSortedArray()

//testIsSameTree()

//testBinaryTree()

//testMaxDepthInTree()

//testEntryNodeOfLoop()

//testReverseListFunc()

//testIsSubtree()

testMirrorBinary()

// 程序执行结束
group.wait()
print("\nFinished!")
