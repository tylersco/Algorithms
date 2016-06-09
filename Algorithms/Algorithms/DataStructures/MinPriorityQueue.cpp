//
//  MinPriorityQueue.cpp
//
//  Implementation of a min priority queue class
//  See MinPriorityQueue.hpp
//
//  Algorithms
//
//  Created by Tyler Scott on 6/8/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <climits>
#include <iostream>
#include "MinPriorityQueue.hpp"

MinPriorityQueue::MinPriorityQueue() : MinHeap() {}

//Return the minimum element in the priority queue
int MinPriorityQueue::minimum() {
    if(heapSize > 0)
        return heap[0];
    else
        throw "There are no elements in the heap.\n";
}

//Extract the min element in the priority queue, re-heapify the queue and return the min element
int MinPriorityQueue::extractMin() {
    if(heapSize > 0) {
        int min = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;
        //Re-heapify the priority queue
        minHeapify(0);
        return min;
    }
    else
        throw "There are no elements in the heap.\n";
    
}

//Decrease the element at index i to have a new value equal to key
void MinPriorityQueue::decreaseKey(int i, int key) {
    
    if(key > heap[i])
        throw "The key cannot be larger than the heap element value.\n";
    
    heap[i] = key;
    
    //Let the element with new value key sift up the heap until it finds the correct position
    //to maintain the min heap property
    while(i > 0 && heap[parent(i)] > heap[i]) {
        int temp = heap[parent(i)];
        heap[parent(i)] = heap[i];
        heap[i] = temp;
        i = parent(i);
    }
    
}

//Insert a new element with value key into the priority queue
void MinPriorityQueue::insert(int key) {
    heapSize++;
    heap[heapSize - 1] = INT_MAX;
    decreaseKey(heapSize - 1, key);
}
