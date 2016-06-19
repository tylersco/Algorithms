//
//  QueueTest.cpp
//
//  Test functionality of the Queue class
//  See Queue.hpp and Queue.cpp
//
//  Algorithms
//
//  Created by Tyler Scott on 6/16/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Queue.hpp"

int main(int argc, const char * argv[]) {
    Queue q;
    ElementTypePtr e = NULL;
    
    q.print();
    
    for(int i = 0; i < 10; i++) {
        e = new(ElementType);
        e->key = i;
        q.enqueue(e);
        q.print();
    }
    
    for(int i = 0; i < 10; i++) {
        q.dequeue();
        q.print();
    }
    
}
