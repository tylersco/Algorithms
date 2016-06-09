//
//  MinPriorityQueue.hpp
//
//  Header file for a min priority queue class
//
//  Algorithms
//
//  Created by Tyler Scott on 6/8/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#ifndef MinPriorityQueue_hpp
#define MinPriorityQueue_hpp

#include <iostream>
#include "MinHeap.hpp"

//Min Priority Queue class which inherits from the MinHeap class
class MinPriorityQueue : public MinHeap {
public:
    MinPriorityQueue();     //Constructor
    int minimum();      //Return the minimum value in the priority queue
    int extractMin();   //Extract the min value in the queue and re-heapify
    void decreaseKey(int i, int key);   //Decrease the element at index i to the value, key
    void insert(int key);       //Insert a new element into the heap with value, key
};

#endif /* MinPriorityQueue_hpp */
