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
        O(n+m)+ O(n+m)
    
    Space Complexity - 
        O(n+m)

*/

#include<bits/stdc++.h>
using namespace std;

void mergeSortedArrays(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> arr3(n1 + n2);
    int left = 0, right = 0;
    int index = 0;
    while (left < n1 && right < n2) {
        if (arr1[left] <= arr2[right]) {
            arr3[index++] = arr1[left++];
        } else {
            arr3[index++] = arr2[right++];
        }
    }

    while ( left < n1) {
        arr3[index++] = arr1[left++];
    }
    while (right < n2) {
        arr3[index++] = arr2[right++];
    }

    for (int i = 0; i < n1+n2; i++) {
        if (i < n1) arr1[i] = arr3[i];
        else arr2[i - n1] = arr3[i];
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