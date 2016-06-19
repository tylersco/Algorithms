//
//  Queue.cpp
//
//  Implementation of a circular queue data structure using an array
//
//  Algorithms
//
//  Created by Tyler Scott on 6/17/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <iostream>
#include "Queue.hpp"

//Constructor
Queue::Queue() {
    //Initialize queue array
    queue = new ElementTypePtr[MAX_LENGTH];
    front = 0;
    rear = 0;
    queue[front] = NULL;
}

//Increment value to help with circular queue indexing
int Queue::incr(int n) {
    return (n + 1) % MAX_LENGTH;
}

bool Queue::isEmpty() {
    if(front == rear and queue[front] == NULL)
        return true;
    else
        return false;
}

//Enqueue (insert) an element into the circular queue
void Queue::enqueue(ElementTypePtr e) {
    if(incr(rear) == front) {
        return;
    }
    
    if(isEmpty()) {
        queue[front] = e;
        return;
    }
    
    rear = incr(rear);
    queue[rear] = e;
    return;
    
}

//Dequeue (delete) an element from the circular queue
ElementTypePtr  Queue::dequeue() {
    if(isEmpty()) {
        return NULL;
    }
    
    if(front == rear) {
        ElementTypePtr val = queue[front];
        queue[front] = NULL;
        return val;
    }
    
    ElementTypePtr val = queue[front];
    front = incr(front);
    return val;
}

//Print the queue
void Queue::print() {
    if(isEmpty()) {
        std::cout << "[]\n";
        return;
    }
    
    std::cout << "[";
    for(int i = front; i <= rear; i++) {
        if(i != rear)
            std::cout << queue[i]->key << ", ";
        else
            std::cout << queue[i]->key;
    }
    std::cout << "]\n";
}