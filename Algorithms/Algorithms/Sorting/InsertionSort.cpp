//
//  InsertionSort.cpp
//
//  Insertion Sort is analogous to how a human sorts a pile of cards face down on a table. Pick up each card in the pile
//  and shuffle it down your current hand, looking for the spot in the already-sorted-hand where it fits. Note that all of
//  the cards in your hand are always sorted.
//
//  Algorithms
//
//  Created by Tyler Scott on 5/30/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <iostream>

void InsertionSort(int *arr, int n) {
    
    for(int i = 1; i < n; i++) {
        
        //Store the value at index i
        int value = arr[i];
        int j = i;
        
        //While you have not reached the beginning of the array and the element is still smaller than the element at index j-1
        while(j > 0 and arr[j-1] > value) {
            //Shift the element at index j-1 to the element at index j and decrement j
            arr[j] = arr[j-1];
            j--;
        }
        //At this point, element j is the index where "value" fits into the sorted contiguous subarray
        arr[j] = value;
    }
    
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {-5, 4, 9, 2, 0, 2, -10, 11, 6};
    int n = 9;
    InsertionSort(arr, n);
    
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
    
    return 0;
}
