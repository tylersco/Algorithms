//
//  QuickSort.cpp
//
//  Quick sort is a divide and conquer sorting algorithm based on a pivot value. It is the one of the best sorting algorithms
//  with an expected running time of O(nlogn) and worst case of O(n^2)
//
//  Algorithms
//
//  Created by Tyler Scott on 6/11/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <iostream>

int partition(int *arr, int p, int r) {
    
    //Set the pivot to be the last element in the subarray
    int x = arr[r];
    int i = p - 1;
    
    for(int j = p; j < r; j++) {
        //If we find a value in the array that is less than or equal to the pivot
        if(arr[j] <= x) {
            i++;
            //Exchange the value at index i with the value at index j
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //Exchange the pivot value with the value at index i+1
    int temp = arr[r];
    arr[r] = arr[i + 1];
    arr[i + 1] = temp;
    
    return i + 1;
    
}

void QuickSort(int *arr, int p, int r) {
    //Use divide and conquer paradigm
    if(p < r) {
        int q = partition(arr, p, r);
        QuickSort(arr, p, q - 1);
        QuickSort(arr, q + 1, r);
    }
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {5, 2, 6, 1, 9, -3, 11, -2, 8};
    int n = 9;
    
    QuickSort(arr, 0, n - 1);
    
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
    
}
