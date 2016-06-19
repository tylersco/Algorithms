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

struct ElementType {
    int key;
};

typedef ElementType * ElementTypePtr;

class Stack {
private:
    ElementTypePtr *stack;     //Pointer to stack array
    int stackSize;  //Size of the array
    int stackTop;   //Index for top of the stack
public:
    Stack(int);       //Constructor
    bool StackEmpty();  //Check if the stack is empty
    void push(ElementTypePtr);   //Push a value onto the stack
    ElementTypePtr pop();          //Pop a value off of the stack
    void print();       //Print the current state of the stack
};

#endif /* Stack_hpp */
