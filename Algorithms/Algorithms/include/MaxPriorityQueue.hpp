//
//  MaxPriorityQueue.hpp
//
//  Header file for a max priority queue class
//
//  Algorithms
//
//  Created by Tyler Scott on 6/5/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#ifndef MaxPriorityQueue_hpp
#define MaxPriorityQueue_hpp

#include <iostream>
#include "MaxHeap.hpp"

//Max Priority Queue class which inherits from the MaxHeap class
class MaxPriorityQueue : public MaxHeap {
public:
    MaxPriorityQueue();     //Constructor
    int maximum();          //Return max element in heap
    int extractMax();       //Extract max element in heap and re-heapify
    void increaseKey(int i, int key);   //Increase the element at index i to the value, key
    void insert(int key);       //Insert a new element into the heap with value, key
};

#endif /* MaxPriorityQueue_hpp */
