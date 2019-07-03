//
//  Singleton.swift
//  algorithm
//
//  Created by Kai on 2019/6/30.
//  Copyright © 2019 kai. All rights reserved.
//

import Foundation

// 单例
class Singleton {
    
    private static var _instance: Singleton?
    private static let queue = DispatchQueue(label: "com.singleton.serialQueue")
    private static let lock = NSLock()
    
    class func instance1() -> Singleton? {
        if _instance == nil {
            queue.sync {
                if _instance == nil {
                    print("Create instance1")
                    _instance = Singleton()
                }
            }
        }
        return _instance
    }
    
    class func instance2() -> Singleton? {
        if _instance == nil {
            lock.lock()
            defer { lock.unlock() }
            _instance = Singleton()
            print("Create instance1")
        }
        return _instance
    }
    
    func log() {
        print(self)
        print("Test")
    }
}


