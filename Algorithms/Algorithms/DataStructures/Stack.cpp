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
    stack = new int[n];
    stackSize = n;
    stackTop = 0;
}

bool Stack::StackEmpty() {
    if(stackTop == 0)
        return true;
    else
        return false;
}

void Stack::push(int x) {
    if(stackTop >= stackSize)
        throw "Stack overflow error\n";
    else {
        stack[stackTop] = x;
        stackTop++;
    }
}

int Stack::pop() {
    if(!StackEmpty()) {
        stackTop--;
        return stack[stackTop];
    }
    else
        throw "Stack underflow error\n";
}

void Stack::print() {
    if(!StackEmpty()) {
        for(int i = 0; i < stackTop; i++)
            std::cout << stack[i] << " ";
        std::cout << "\n";
    }
    else
        std::cout << "Stack is empty.\n";
}