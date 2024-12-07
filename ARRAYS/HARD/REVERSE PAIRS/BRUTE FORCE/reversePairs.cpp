/*
    Problem Statement: Reverse Pairs
        Given an integer array nums, your task is to find the number of reverse pairs in the array. 
        A reverse pair is defined as a pair of indices (i, j) such that:
            0 ≤ i < j < nums.length, and
            nums[i] > 2 * nums[j].
        
        Input - 
            nums = [2, 4, 3, 5, 1]
        Output - 
            3

        Explanation:
            The reverse pairs are:
            (0, 4) → nums[0] = 2 and nums[4] = 1,
            (1, 4) → nums[1] = 4 and nums[4] = 1, and
            (2, 4) → nums[2] = 3 and nums[4] = 1.
*/

/*
    Time Complexity-
        O(n^2)
        
    Space Complexity - 
        O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int reversePairs(vector<int> &arr) {
    int n = arr.size();
    int cnt = 0;
    for (int i= 0; i< n; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > (2*arr[j])) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {

  vector<int> arr = {40, 25, 19, 12, 9, 6, 2};

  int res = reversePairs(arr);
  
  cout << "The number of reverse pairs is : " << res << endl;

  return 0;
}