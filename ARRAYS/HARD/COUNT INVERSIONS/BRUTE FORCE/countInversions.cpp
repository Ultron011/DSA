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
        O(n^2)

    Space Compleixty -
        O(1)
        
*/

#include<bits/stdc++.h>
using namespace std;

int inversionCount(vector<int> &arr) {
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i< n; i++) {
        for (int j = i+1; j < n;j++) {
            if (arr[i] > arr[j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {

  vector<int> arr = {5, 3, 2, 4, 1};
  
  int count = inversionCount(arr);

  cout << "Inversion Count is : " << count << endl;

  return 0;
}