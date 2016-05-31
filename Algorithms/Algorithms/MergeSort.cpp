//
//  MergeSort.cpp
//
//  Merge sort takes an array and breaks it down until we have multiple subarrays of size 1, and then combines them
//  back into a single array in sorted order.
//
//  Algorithms
//
//  Created by Tyler Scott on 5/30/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <iostream>
#include <cmath>

void merge(int *arr, int n, int p, int q, int r) {
    
    int n1 = q - p + 1;
    int* left = new int[n1];
    
    int n2 = r - q;
    int* right = new int[n2];
    
    //Fill the left array with the elements of the first subarray we want to combine
    for(int a = 0; a < n1; a++) {
        left[a] = arr[p + a];
    }
    
    //Fill the right array with the elements of the second subarray we want to combine
    for(int b = 0; b < n2; b++) {
        right[b] = arr[q + 1 + b];
    }
    
    int i = 0;
    int j = 0;
    int k = p;

    //Combine the two subarrays
    while(i < n1 and j < n2) {
        if(left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    while(i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while(j < n2) {
        arr[k] = arr[q + 1 + j];
        j++;
        k++;
    }
    
}

void MergeSort(int *arr, int n, int p, int r) {
    //If the size of the subarray is greater than 1, keep breaking down the array
    if(p < r) {
        int q = floor((p + r) / 2);
        MergeSort(arr, n, p, q);
        MergeSort(arr, n, q + 1, r);
        merge(arr, n, p, q, r);
    }
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {-5, 1, 4, 2, 10, -8, 9};
    int n = 7;
    MergeSort(arr, n, 0, n-1);
    
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
    
    
    return 0;
}
