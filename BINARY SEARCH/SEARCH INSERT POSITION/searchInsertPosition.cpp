/*
    Problem Statement: 
    You are given a sorted array arr of distinct values and a target value x. 
    You need to search for the index of the target value in the array.
    If the value is present in the array, then return its index. Otherwise, 
    determine the index where it would be inserted in the array while maintaining the sorted order.

    Input Format: 
        arr[] = {1,2,4,7}, x = 6
    Result: 
        3
    Explanation: 
        6 is not present in the array. So, if we will insert 6 in the 3rd index(0-based indexing), 
        the array will still be sorted. {1,2,4,6,7}.
    
*/

#include<bits/stdc++.h>
using namespace std;

int insertPosition(vector<int> &arr, int x) {
    int n = arr.size();
    int ans = n;
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {

  vector<int> arr= {1, 2, 4, 7};
  int x;
  cin >> x;

  int insertIndex = insertPosition(arr, x);
  cout << "Insert at index : " << insertIndex << endl;

  return 0;
}