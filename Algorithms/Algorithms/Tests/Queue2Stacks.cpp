//
//  Queue2Stacks.cpp
//
//  Test file to implement a queue using 2 stacks
//
//  Algorithms
//
//  Created by Tyler Scott on 6/19/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Stack.hpp"

//Enqueue operation of a queue using 2 stacks, O(1)
void enqueue(ElementTypePtr e, Stack *s1) {
    s1->push(e);
    return;
}

//Dequeue operation of a queue using 2 stacks, O(n)
ElementTypePtr dequeue(Stack *s1, Stack *s2) {
    
    if(s2->StackEmpty()) {
        //Pop off everything on stack 1 and move it to stack 2
        while(!s1->StackEmpty()) {
            ElementTypePtr e = s1->pop();
            s2->push(e);
        }
    }
    //Pop one element off of stack 2 and that is the return element of dequeue
    return s2->pop();

}

int main(int argc, const char * argv[]) {
    Stack s1(5);
    Stack s2(5);
    
    ElementTypePtr e;
    
    for(int i = 0; i < 3; i++) {
        e = new ElementType;
        e->key = i;
        enqueue(e, &s1);
        s1.print();
    }
    
    e = dequeue(&s1, &s2);
    
    std::cout << e->key << "\n";
    
    e = dequeue(&s1, &s2);
    
    std::cout << e->key << "\n";
    
    e = dequeue(&s1, &s2);
    
    std::cout << e->key << "\n";
    
    return 0;
    
}
