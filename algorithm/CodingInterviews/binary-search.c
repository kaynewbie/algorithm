//
//  binary-search.c
//  algorithm
//
//  Created by Kai on 2019/7/10.
//  Copyright © 2019 kai. All rights reserved.
//

#include "binary-search.h"

bool binarySearch(int *p, int length, int target) {
    int indexMid = 0;
    int valueMid = 0;
    
    int i = 0;
    while (length > 0) {
        printf("current loop=%d\n", i++);
        indexMid = (length - 1) >> 1;
        valueMid = *(p+indexMid);
        
        if (target == valueMid) {
            return true;
        } else if (target > valueMid) {
            p += indexMid + 1;
            length -= 1 + indexMid;
        } else {
            length = indexMid;
        }
    }
    return false;
}

void testBinarySearch() {
    int target = 666;
    int p[13] = {1, 1, 20, 34, 67, 100, 101, 102, 200, 234, 456, 789, 7777};
    bool result = binarySearch(p, 13, target);
    printf("Binary search result=%d", result);
}
