//
//  Stack2Queues.cpp
//
//  Implement a stack with 2 queues
//
//  Algorithms
//
//  Created by Tyler Scott on 7/2/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Queue.hpp"

//Push operation of a stack using enqueue
void push(ElementTypePtr e, Queue *q) {
    q->enqueue(e);
    return;
}

//Pop operation of stack using a combination of dequeue and enqueue
ElementTypePtr pop(Queue *q1, Queue *q2) {
    if(q1->isEmpty())
        return NULL;
    
    ElementTypePtr e = NULL;
    
    while(!q1->isEmpty()) {
        e = q1->dequeue();
        
        if(!q1->isEmpty())
            q2->enqueue(e);
        
    }
    
    //Swap the contents of queue 1 and queue 2
    Queue temp = *q1;
    *q1 = *q2;
    *q2 = temp;
    
    return e;
}

int main(int argc, const char * argv[]) {
    
    Queue q1;
    Queue q2;
    
    ElementTypePtr e;
    
    for(int i = 0; i < 3; i++) {
        e = new ElementType;
        e->key = i;
        push(e, &q1);
        q1.print();
    }
    
    e = pop(&q1, &q2);
    q1.print();
    
    //std::cout << e->key << "\n";
    
    e = pop(&q1, &q2);
    q1.print();
    push(e, &q1);
    q1.print();
    
    //std::cout << e->key << "\n";
    
    e = pop(&q1, &q2);
    q1.print();
    
    //std::cout << e->key << "\n";
    
    return 0;
}
