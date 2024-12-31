/*
    Problem Statement: 
        Given an array of N integers. Every number in the array except one appears twice. 
        Find the single number in the array.

    Input Format:
        arr[] = {1,1,2,2,3,3,4,5,5,6,6}

    Result:
        4

    Explanation:
        Only the number 4 appears once in the array.

*/

#include<bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &arr) {
    int n = arr.size();

    if (n == 1) return arr[0];

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            if (arr[i] != arr[i+1]) return arr[0];
        }
        else if (i == n - 1) {
            if (arr[i] != arr[i-1]) return arr[n-1];
        }
        else {
            if (arr[i] != arr[i-1] && arr[i] != arr[i+1]) return arr[i];
        }
    }
}

int main() {

  vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
  int ans = singleElement(arr);

  cout << "Single Element is : " << ans << endl;

  return 0;
}