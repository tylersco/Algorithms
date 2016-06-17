//
//  Stack.hpp
//
//  Header file for a Stack class
//
//  Algorithms
//
//  Created by Tyler Scott on 6/16/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp

#include <stdio.h>
#include <iostream>

class Stack {
private:
    int *stack;     //Pointer to stack array
    int stackSize;  //Size of the array
    int stackTop;   //Index for top of the stack
public:
    Stack(int n);       //Constructor
    bool StackEmpty();  //Check if the stack is empty
    void push(int x);   //Push a value onto the stack
    int pop();          //Pop a value off of the stack
    void print();       //Print the current state of the stack
};

#endif /* Stack_hpp */
