/*
    Problem Statement: Count Subarrays with XOR Equal to K
        You are given an array of integers arr of size n and an integer k. Your task is to find the number of subarrays (contiguous segments of the array) whose XOR is equal to k.

    Input:
        n = 5
        k = 4
        arr = [4, 2, 2, 6, 4]
    
    Output - 
        4
    
    Explanation:
        The subarrays whose XOR equals 4 are:
            [4] (XOR = 4)
            [4, 2, 2] (XOR = 4)
            [2, 6, 4] (XOR = 4)
            [4] (XOR = 4)
*/

/*
    Time complexity - 
        O(n^3)

    Space complexity - 
        O(1)

*/

#include<bits/stdc++.h>
using namespace std;

int countSubarray(vector<int> &arr, int k) {
    int n = arr.size();

    int cnt = 0;
    for (int i= 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int res = 0;
            for (int k = i; k <= j; k++) {
                res ^= arr[k]; 
            }
            if (res == k) cnt++;
        }
    }

    return cnt;
}

int main() {
  
  vector<int> arr = {4, 2, 2, 6, 4};
  int k = 6;

  cout << countSubarray(arr, k) << endl;

  

  return 0;
}