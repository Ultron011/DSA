/*
    Problem Statement:
    Given a sorted array arr and a target value x, the lower bound of x in
    the array is defined as the smallest index i such that arr[i] >= x. If 
    no such index exists, the lower bound is considered to be the length of the array.

    Input:
        Array: [1, 3, 5, 7, 9]
        Target: 5
    
    Output:
        Lower Bound: 2 (since arr[2] = 5)
*/

/*
    Time complexity - 
        O(log(n))
    Space complexity - 
        O(1)
*/


#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int x) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}

/*
    STL - 
        lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
*/

int main() {

  vector<int> arr= {1, 2, 3,3, 7, 8, 9, 9, 9, 11};
  cout << "Enter x: ";
  int x;
  cin >> x;

  int lowerBoundIndex = lowerBound(arr, x);
  cout << "Lower Bound : " << lowerBoundIndex << endl;

  return 0;
}