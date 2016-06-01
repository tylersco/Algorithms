//
//  MaxSubarray.cpp
//
//  Max Subarray is a divide and conquer algorithm which finds a contiguous subarray that has the largest sum. The famous example is finding the best days/times
//  to buy and sell a stock.
//
//  Algorithms
//
//  Created by Tyler Scott on 6/1/16.
//  Copyright © 2016 Tyler Scott. All rights reserved.
//

#include <iostream>
#include <limits.h>

//Find the max value of two integers
int max(int a, int b) {
    return (a >= b) ? a : b;
}

//Find the max value of three integers
int max(int a, int b, int c) {
    return max(max(a, b), c);
}

int MaxCrossingSubarray(int *arr, int p, int q, int r) {
    
    int leftSum = INT_MIN;
    int tempSum = 0;
    
    //Find the max sum in the left half of the array
    for(int i = q; i >= p; i--) {
        tempSum += arr[i];
        if(tempSum > leftSum)
            leftSum = tempSum;
    }
    
    int rightSum = INT_MIN;
    tempSum = 0;
    
    //Find the max sum in the right half of the array
    for(int j = q+1; j <= r; j++) {
        tempSum += arr[j];
        if(tempSum > rightSum)
            rightSum = tempSum;
    }
    
    return leftSum + rightSum;
    
}

int MaxSubarray(int *arr, int p, int r) {
    
    if(p > r)
        return 0;
    else if(p == r)
        return arr[p];
    else {
        //Calculate the mid index of the array
        int q = (p + r) / 2;
        //We know that the max subarray is either fully in the left half, fully in the right half, or crossing into both halves of the array
        return max(MaxSubarray(arr, p, q), MaxSubarray(arr, q+1, r), MaxCrossingSubarray(arr, p, q, r));
    }
    
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {-5, 3, 1, -2, 9, -11, 13, -3, 2, 3};
    int sum = MaxSubarray(arr, 0, 9);
    std::cout << sum << "\n";
    
    return 0;
}
