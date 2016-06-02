//
//  MinHeap.cpp
//
//  Implementation of a min binary heap class
//  See MinHeap.hpp
//
//  Algorithms
//
//  Created by Tyler Scott on 6/1/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <iostream>
#include "MinHeap.hpp"

MinHeap::MinHeap() {
    heapSize = 0;
    heap = NULL;
}

//Return the parent index for a given index in the array, i
int MinHeap::parent(int i) {
    int parent = (i / 2) - 1;
    return parent;
}

//Return the index of the left child for a given index in the array, i
int MinHeap::left(int i) {
    return 2 * i + 1;
}

//Return the index of the right child for a given index in the array, i
int MinHeap::right(int i) {
    return 2 * i + 2;
}

//Take an index in the heap and min heapify from that index
//Assume that the left index and right index are min heaps, themselves
void MinHeap::minHeapify(int i) {
    if(i < heapSize) {
        int smallest;
        int left_index = left(i);
        
        if(left_index < heapSize && heap[left_index] < heap[i])
            smallest = left_index;
        else
            smallest = i;
        
        int right_index = right(i);
        if(right_index < heapSize && heap[right_index] < heap[smallest])
            smallest = right_index;
        
        //If the heap was not a min heap, trickle down the child containing 'smallest', and min heapify that sub-heap
        if(smallest != i) {
            int temp = heap[i];
            heap[i] = heap[smallest];
            heap[smallest] = temp;
            
            minHeapify(smallest);
        }
    }
}

//Build a min heap from an array
void MinHeap::buildMinHeap(int *arr, int n) {
    heapSize = n;
    heap = arr;
    
    //We only need to loop down from heapSize / 2 because all nodes above that are leaves
    for(int i = heapSize / 2; i >= 0; i--) {
        minHeapify(i);
    }
}