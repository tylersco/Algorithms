//
//  SelectionSort.cpp
//
//  Selection sort loops through the array, on the first iteration, it finds the smallest element and replaces that with the
//  first element. On the second iteration, it finds the second smallest element and replaces that with the second element.
//  ... and so on.
//
//  Algorithms
//
//  Created by Tyler Scott on 5/30/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <iostream>

void SelectionSort(int *arr, int n) {
    
    for(int i = 0; i < n; i++){
        
        //Initalize integer to store the index of the smallest element
        int smallestIndex = i;
        
        for(int j = i; j < n; j++) {
            
            //If the element at index j is smaller than the element at the current smallest index, update smallest index
            if(arr[j] < arr[smallestIndex])
                smallestIndex = j;
        }
        
        //Switch the element at index i with the smallest element found
        int temp = arr[i];
        arr[i] = arr[smallestIndex];
        arr[smallestIndex] = temp;
        
    }
}

int main(int argc, const char * argv[]) {

    int arr[] = {-3, 2, 9, 1, -6, 7, 7, 4};
    int n = 8;
    SelectionSort(arr, n);
    
    for(int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
    
    return 0;
}
