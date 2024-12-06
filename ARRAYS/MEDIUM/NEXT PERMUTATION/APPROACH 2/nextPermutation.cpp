/*  Problem Statement : 

    Given an array of distinct integers representing a permutation, 
    write a function to find the next lexicographical permutation of the array.
    If such a permutation doesn't exist (i.e., the array is sorted in descending order), 
    the function should return the lowest permutation (i.e., the array sorted in ascending order).

    Input - 
        nums = [1, 2, 3]
    
    Output - 
        [1, 3, 2]
    
    Explanation - 
        The next permutation of [1, 2, 3] is [1, 3, 2].
*/

/*
    Time complexity - 
        O(n)
    
    Space complexity - 
        O(1)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &arr) {
    int n = arr.size();
    int dipIndex = -1;
    for (int i = n - 2;i >= 0 ; i--) {
        if (arr[i] < arr[i+1]) {     
            dipIndex = i;
            break;
        }
    }

    if (dipIndex == -1) {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > arr[dipIndex]) {
            swap(arr[i], arr[dipIndex]);
            break;
        }
    }

    reverse(arr.begin() + dipIndex + 1 , arr.end());
    return arr;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> ans = nextPermutation(arr);
  for (int i: ans) {
    cout << i << " ";
  }

  return 0;
}