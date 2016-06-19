//
//  Queue.hpp
//
//  Header file for a circular queue implemented with an array
//
//  Algorithms
//
//  Created by Tyler Scott on 6/17/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>

const int MAX_LENGTH = 8;

//Structure to contain elements of the queue
struct ElementType {
    int key;
};

//Declare a type for an Element Type Pointer
typedef ElementType * ElementTypePtr;

class Queue {
private:
    ElementTypePtr *queue; //Pointer to queue array
    int front;  //Front of the queue
    int rear;   //Rear of the queue
    
public:
    Queue();    //Constructor
    int incr(int);    //Increment method to help with indexing the circular queue
    bool isEmpty();
    void enqueue(ElementTypePtr);    //Enqueue operation
    ElementTypePtr dequeue();          //Dequeue operation
    void print();           //Print the state of the queue
};

#endif /* Queue_hpp */
