//
//  MaxPriorityQueue.cpp
//
//  Implementation of a max priority queue class
//  See MaxPriorityQueue.hpp
//
//  Algorithms
//
//  Created by Tyler Scott on 6/5/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <climits>
#include <iostream>
#include "MaxPriorityQueue.hpp"

MaxPriorityQueue::MaxPriorityQueue() : MaxHeap() {}

//Return the maximum element in the priority queue
int MaxPriorityQueue::maximum() {
    if(heapSize > 0)
        return heap[0];
    else
        throw "There are no elements in the heap.\n";
}

//Extract the max element in the priority queue, re-heapify the queue and return the max element
int MaxPriorityQueue::extractMax() {
    if(heapSize > 0) {
        int max = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;
        //Re-heapify the priority queue
        maxHeapify(0);
        return max;
    }
    else
        throw "There are no elements in the heap.\n";
}

//Increase the element at index i to have a new value equal to key
void MaxPriorityQueue::increaseKey(int i, int key) {
    if(key < heap[i]) {
        throw "The key cannot be smaller than the heap element value.\n";
    }
    
    heap[i] = key;
    
    //Let the element with new value key sift up the heap until it finds the correct position
    //to maintain the max heap property
    while(i > 0 && heap[parent(i)] < heap[i]) {
        int temp = heap[parent(i)];
        heap[parent(i)] = heap[i];
        heap[i] = temp;
        i = parent(i);
    }
    
}

//Insert a new element with value key into the priority queue
void MaxPriorityQueue::insert(int key) {
    heapSize++;
    heap[heapSize - 1] = INT_MIN;
    increaseKey(heapSize - 1, key);
}
