/*
  Problem Statement: Leaders in an Array
  Given an array of integers, your task is to find all the leaders in the array. 
  An element is considered a leader if it is greater than or equal to all the elements to its right side. 
  The rightmost element is always a leader.  

  Input:
    arr = [16, 17, 4, 3, 5, 2]

  Output:
    [17, 5, 2]
  
  Explanation:
    17 is greater than all elements to its right.
    5 is greater than all elements to its right.
    2 is the last element, so it is always a leader.
*/

/*
  Time complexity - 
    O(n)
  
  Space complexity - 
    O(n)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> leadersInArray(vector<int> &arr) {
    int n = arr.size();
    vector<int> temp;
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
      if (arr[i] > maxi) {
        maxi = arr[i];
        temp.push_back(arr[i]);
      }
    }
    return temp;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> ans = leadersInArray(arr);
  for (int i : ans) {
    cout << i << " ";
  }

  return 0;
}