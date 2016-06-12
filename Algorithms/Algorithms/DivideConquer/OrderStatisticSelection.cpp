//
//  OrderStatisticSelection.cpp
//
//  Use a divide and conquer, randomized algorithm, that selects the ith smallest element in an array. Expected run-time is O(n).
//  We are assuming that the input array has all distinct elements.
//
//  Algorithms
//
//  Created by Tyler Scott on 6/12/16.
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

int randomPartition(int *arr, int p, int r) {
    //Initialize random seed
    srand(time(NULL));
    
    int random_index = rand() % (r - p) + p;
    int temp = arr[r];
    arr[r] = arr[random_index];
    arr[random_index] = temp;
    
    int q = partition(arr, p, r);
    
    return q;
}

int randomSelection(int *arr, int p, int r, int i) {
    //If p and r are equal, subarray is of size 1
    if(p == r)
        return arr[p];
    
    //Partition the array randomly
    int q = randomPartition(arr, p, r);
    int k = q - p + 1;
    
    //If we found the value we want return it
    if(i == k)
        return arr[q];
    //The value we want is in the lower partition
    else if(i < k)
        return randomSelection(arr, p, q - 1, i);
    //The value we want is in the higher partition
    else
        return randomSelection(arr, q + 1, r, i - k);
    
}


int main(int argc, const char * argv[]) {
    
    int arr[] = {5, 3, 9, -2, 7, -8, 11, 1, 0};
    int n = 9;
    
    std::cout << randomSelection(arr, 0, n - 1, 8) << "\n";
    
    return 0;
}
