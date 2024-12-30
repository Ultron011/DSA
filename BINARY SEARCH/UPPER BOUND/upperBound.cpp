/*
    Problem Statement:
    Given a sorted array arr and a target value x, the upper bound of x in 
    the array is defined as the smallest index i such that arr[i] > x. 
    If no such index exists, the upper bound is considered to be the length 
    of the array.

    Input:
        Array: [1, 3, 5, 7, 9]
        Target: 5
    
    Output:
        Lower Bound: 3 (since arr[3] = 7)
*/

/*
    Time complexity - 
        O(log(n))
    Space complexity - 
        O(1)
*/

/*
    STL - 
        ub = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
*/

#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x) {
    int low = 0, high = arr.size() - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

int main() {

  vector<int> arr= {1, 2, 3,3, 7, 8, 9, 9, 9, 11};
  cout << "Enter x: ";
  int x;
  cin >> x;

  int upperBoundIndex = upperBound(arr, x);
  cout << "Lower Bound : " << upperBoundIndex << endl;

  return 0;
}