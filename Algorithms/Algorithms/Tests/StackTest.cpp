//
//  StackTest.cpp
//
//  Test functionality of the Stack class
//  See Stack.hpp and Stack.cpp
//
//  Algorithms
//
//  Created by Tyler Scott on 6/16/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Stack.hpp"

int main(int argc, const char * argv[]) {
    Stack stack(10);
    
    stack.print();
    
    for(int i = 0; i < 10; i++) {
        stack.push(i);
        stack.print();
    }
    
    for(int i = 0; i < 10; i++) {
        stack.pop();
        stack.print();
    }

}
