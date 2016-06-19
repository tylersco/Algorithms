//
//  Stack.cpp
//
//  Implementation of a Stack data structure
//
//  Algorithms
//
//  Created by Tyler Scott on 6/16/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"

//Constructor
Stack::Stack(int n) {
    stack = new ElementTypePtr[n];
    stackSize = n;
    stackTop = 0;
}

bool Stack::StackEmpty() {
    if(stackTop == 0)
        return true;
    else
        return false;
}

void Stack::push(ElementTypePtr e) {
    if(stackTop >= stackSize) {
        return;
    }
    else {
        stack[stackTop] = e;
        stackTop++;
    }
}

ElementTypePtr Stack::pop() {
    if(!StackEmpty()) {
        stackTop--;
        return stack[stackTop];
    }
    else {
        return NULL;
    }
}

void Stack::print() {
    if(!StackEmpty()) {
        std::cout << "[";
        for(int i = 0; i < stackTop; i++)
            if(i != stackTop - 1)
                std::cout << stack[i]->key << ", ";
            else
                std::cout << stack[i]->key << "]\n";
    }
    else
        std::cout << "[]\n";
}