//
//  MinHeap.hpp
//
//  Header file for a min binary heap class
//
//  Algorithms
//
//  Created by Tyler Scott on 6/1/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#ifndef MinHeap_hpp
#define MinHeap_hpp

#include <iostream>

//Min heap class implemented with an array
class MinHeap {
public:
    int heapSize;        //Size of the heap
    int *heap;           //Pointer to the heap
    
    MinHeap();                  //Constructor
    int parent(int i);          //Return index in array of parent
    int left(int i);            //Return index in array of left child
    int right(int i);           //Return index in array of right child
    void minHeapify(int i);         //Turn a heap into a min heap starting at index i
    void buildMinHeap(int *arr, int n);    //Build min heap out of an existing array
};

#endif /* MinHeap_hpp */
