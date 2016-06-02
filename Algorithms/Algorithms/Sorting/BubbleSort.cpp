//
//  BubbleSort.cpp
//
//  On the first iteration of the loop, we start at the end of the array and let the smallest element "sift" down
//  to the first element by repeatedly swapping larger elements with smaller elements. We continue the "sift" method
//  until we have placed every element in the correct position of the array.
//
//  Algorithms
//
//  Created by Tyler Scott on 5/30/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <iostream>

void BubbleSort(int *arr, int n) {
    
    for(int i = 0; i < n; i++) {
        
        //This is the "sift" part of the sort
        for(int j = n-1; j > i; j--) {
            //If we have found a smaller element after a larger element, swap them
            if(arr[j] < arr[j-1]) {
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {-5, -1, 0, 0, 4, 2, 13, -10};
    int n = 8;
    BubbleSort(arr, n);
    
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
    
    return 0;
}
