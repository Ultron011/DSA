/*
    Problem Statement:
    Given an array of integers, count the number of inversions in the array. 
    An inversion is a pair of elements in the array that are in the wrong order, 
    i.e., a larger element appears before a smaller element.

    Input - 
        [2, 4, 1, 3, 5]

    Output - 
        3

    Explanation - 
        (2, 1) is an inversion
        (4, 1) is an inversion
        (4, 3) is an inversion
*/

/* 
    Time Complexity- 
        O(n*log(n))

    Space Compleixty -
        O(n) - (Even though we are deleting the array after use.)
        
*/

#include<bits/stdc++.h>
using namespace std;

int mergeAndSort(vector<int>& arr, int start, int mid, int end) {
    int inversionCount = 0;
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int* left = new int[leftSize];
    int* right = new int[rightSize];

    // Check for memory allocation failure
    if (!left || !right) {
        // Handle memory allocation failure
        cout << "Memory Allocationo Failed. Not enough memory available.";
        exit(0);
    }

    for (int i = 0; i < leftSize; i++) {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < rightSize; j++) {
        right[j] = arr[mid + j + 1];
    }

    int leftIndex = 0, rightIndex = 0;
    int arrIndex = start;
    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (left[leftIndex] <= right[rightIndex]) {
            arr[arrIndex++] = left[leftIndex++];
        } else {
            arr[arrIndex++] = right[rightIndex++];
            inversionCount += (leftSize - leftIndex);
        }
    }

    while (leftIndex < leftSize) arr[arrIndex++] = left[leftIndex++];
    while (rightIndex < rightSize) arr[arrIndex++] = right[rightIndex++];

    delete[] left;
    delete[] right;

    return inversionCount;
}

int inversionCount(const vector<int>& arr, int start, int end) {
    if (start >= end) {
        // Base case: only one element or no elements
        return 0;
    }

    int mid = start + (end - start) / 2;
    int leftInversions = inversionCount(arr, start, mid);
    int rightInversions = inversionCount(arr, mid + 1, end);

    int mergedInversions = mergeAndSort(const_cast<vector<int>&>(arr), start, mid, end);

    return leftInversions + rightInversions + mergedInversions;
}

int main() {

  vector<int> arr = {5, 3, 2, 4, 1};
  
  int count = inversionCount(arr, 0, arr.size() - 1);

  cout << "Inversion Count is : " << count << endl;

  return 0;
}