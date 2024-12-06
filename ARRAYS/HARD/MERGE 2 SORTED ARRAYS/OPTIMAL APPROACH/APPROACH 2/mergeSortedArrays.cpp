/*
    Problem Statement: Merge Two Sorted Arrays
        You are given two sorted arrays, arr1 of size m and arr2 of size n. 
        Your task is to merge these two arrays into a single sorted array in non-decreasing order. 
        The resulting array should contain all elements of arr1 and arr2.
    
    Input - 
        m = 3
        n = 4
        arr1 = [1, 3, 5]
        arr2 = [2, 4, 6, 8]

    Output - 
        [1, 2, 3, 4, 5, 6, 8]

*/

/*
    Time Complexity - 
        O(log(n1+n2)) + O(n+m)
    
    Space Complexity - 
        O(1)

*/

#include<bits/stdc++.h>
using namespace std;

void swapIfGreater(vector<int>&arr1, vector<int> &arr2, int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void mergeSortedArrays(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();

    int len = n1 + n2;
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        int left = 0;
        int right = left + gap;
        while (right < len) {
            if (left < n1 && right >= n1) {
                swapIfGreater(arr1, arr2, left, right - n1);
            } else if(left >= n1) {
                swapIfGreater(arr2, arr2, left-n1, right-n1);
            } else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        if (gap == 1) break;
        gap = (gap / 2) + (gap % 2);
    }

}

int main() {
  
  vector<int> arr1 = {1, 3, 5, 7};
  vector<int> arr2 = {2, 4, 6, 8, 9, 11};

  mergeSortedArrays(arr1, arr2);

  for (int i : arr1) {
    cout << i << " ";
  }
  for (int i : arr2) {
    cout << i << " ";
  }
  

  return 0;
}