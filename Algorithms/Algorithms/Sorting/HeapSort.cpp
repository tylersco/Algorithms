//
//  HeapSort.cpp
//
//  Algorithm to sort an array of numbers using a Max Heap data structure
//
//  Algorithms
//
//  Created by Tyler Scott on 6/2/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <iostream>
#include "MaxHeap.hpp"

void HeapSort(MaxHeap *maxHeap) {
    
    //While we still have values to sort
    while(maxHeap->heapSize - 1 > 0) {
        
        //Swap the first element in the array (largest element) with the element at heap size - 1
        int temp = maxHeap->heap[0];
        maxHeap->heap[0] = maxHeap->heap[maxHeap->heapSize - 1];
        maxHeap->heap[maxHeap->heapSize - 1] = temp;
        
        maxHeap->heapSize--;
        
        //The heap may have gotten messed up when we swapped, so re-max-heapify the array
        maxHeap->maxHeapify(0);
    }
    
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {-2, 5, 3, 8, 0, -10, 2, 12};
    int n = 8;
    
    MaxHeap *maxHeap = new MaxHeap();
    
    //Build the max heap
    maxHeap->buildMaxHeap(arr, n);
    
    HeapSort(maxHeap);
    
    for(int i = 0; i < n; i++)
        std::cout << maxHeap->heap[i] << " ";
    std::cout << "\n";
    
    return 0;
}
