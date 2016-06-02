//
//  MaxHeap.hpp
//
//  Header file for a max binary heap class
//
//  Algorithms
//
//  Created by Tyler Scott on 6/1/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#ifndef MaxHeap_hpp
#define MaxHeap_hpp

#include <iostream>

//Max heap class implemented with an array
class MaxHeap {
public:
    int heapSize;        //Size of the heap
    int *heap;           //Pointer to the heap
    
    MaxHeap();                  //Constructor
    int parent(int i);          //Return index in array of parent
    int left(int i);            //Return index in array of left child
    int right(int i);           //Return index in array of right child
    void maxHeapify(int i);         //Turn a heap into a max heap starting at index i
    void buildMaxHeap(int *arr, int n);    //Build max heap out of an existing array
};

#endif /* MaxHeap_hpp */
