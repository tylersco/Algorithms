//
//  MaxHeap.cpp
//
//  Implementation of a max binary heap class
//  See MaxHeap.hpp
//
//  Algorithms
//
//  Created by Tyler Scott on 6/1/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <iostream>
#include "MaxHeap.hpp"

MaxHeap::MaxHeap() {
    heapSize = 0;
    heap = NULL;
}

//Return the parent index for a given index in the array, i
int MaxHeap::parent(int i) {
    int parent = (i / 2) - 1;
    return parent;
}

//Return the index of the left child for a given index in the array, i
int MaxHeap::left(int i) {
    return 2 * i + 1;
}

//Return the index of the right child for a given index in the array, i
int MaxHeap::right(int i) {
    return 2 * i + 2;
}

//Take an index in the heap and max heapify from that index
//Assume that the left index and right index are max heaps, themselves
void MaxHeap::maxHeapify(int i) {
    if(i < heapSize) {
        int largest;
        int left_index = left(i);
        
        if(left_index < heapSize && heap[left_index] > heap[i])
            largest = left_index;
        else
            largest = i;
        
        int right_index = right(i);
        if(right_index < heapSize && heap[right_index] > heap[largest])
            largest = right_index;
        
        //If the heap was not a max heap, trickle down the child containing 'largest', and max heapify that sub-heap
        if(largest != i) {
            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            
            maxHeapify(largest);
        }
    }
}

//Build a max heap from an array
void MaxHeap::buildMaxHeap(int *arr, int n) {
    heapSize = n;
    heap = arr;
    
    //We only need to loop down from heapSize / 2 because all nodes above that are leaves
    for(int i = heapSize / 2; i >= 0; i--) {
        maxHeapify(i);
    }
}