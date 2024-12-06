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
        O(min(n1, n2)) + O(n1*log(n1)) + O(n2*log(n2))
    
    Space Complexity - 
        O(1)

*/

#include<bits/stdc++.h>
using namespace std;

void mergeSortedArrays(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size();
    int n2 = arr2.size();

    int left = n1 - 1;
    int right = 0;
    while (left >= 0 && right < n2) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            right++;
            left--;
        } else {
            break;
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

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