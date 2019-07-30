#include "stack.h"
#include "stdlib.h"
#include "string.h"


/**
 创建栈

 @param memberSize 元素大小
 @param totalElements 元素数量
 */
Stack* createStack(int memberSize, int totalElements) {
    Stack *s = malloc(sizeof(Stack));
    s->top = -1;
    s->memberSize = memberSize;
    s->totalElements = totalElements;
    s->data = malloc(totalElements*memberSize);
    return s;
}

int stackDestroy(Stack *s) {
    free(s->data);
    free(s);
    return 0;
}

int expandStack(Stack* s) {
    //double total capacity of the stack
    s->data = realloc(s->data, s->totalElements * 2 * s->memberSize);
    s->totalElements *= 2;
    return 0;
}

int stackPush(Stack *s,  void *data) {
    //check is the stack is full
    if (s->top == s->totalElements - 1) {
        //if full, call expand function to expand the size of the stack
        expandStack(s);
    }
    s->top++;
    //calculate starting location for the new element
    void* target = (char*)s->data+(s->top*s->memberSize);
    memcpy(target, data, s->memberSize);
    return 0;
}

int stackTop(Stack *s,  void *target) {
    if (s->top == -1) {
        return 1;
    }
    void* source = (char*)s->data+(s->top*s->memberSize);
    memcpy(target, source, s->memberSize);
    return 0;
}

int stackPop(Stack *s,  void *target) {
    if (s->top == -1) {
        return 1;
    }
    void* source = (char*)s->data+(s->top*s->memberSize);
    s->top--;
    memcpy(target, source, s->memberSize);
    return 0;
}

int getMax(Stack *s, void* max, int (*compare)(const void *a, const void *b)) {
    if(s->top == -1) {
        return 1;
    }
    void* maxTemp = s->data;
    int i = 1;
    while(i++ <= s->top) {
        void* b = (char*)s->data + s->memberSize*i;
        int result = compare(maxTemp, b);
        if(result == 1) {
            maxTemp = b;
        }
    }
    memcpy(max, maxTemp, s->memberSize);
    return 0;
}
