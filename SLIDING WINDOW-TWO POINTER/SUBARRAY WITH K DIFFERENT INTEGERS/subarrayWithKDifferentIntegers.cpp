/*
 * LeetCode Problem 992: Subarrays with K Different Integers
 *
 * Problem Statement:
 * Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.
 * (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
 * Return the number of good subarrays of A.
 *
 * Example 1:
 * Input: A = [1,2,1,2,3], K = 2
 * Output: 7
 * Explanation: Subarrays formed with exactly 2 different integers are:
 * [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,3]
 *
 * Example 2:
 * Input: A = [1,2,1,3,4], K = 3
 * Output: 3
 * Explanation: Subarrays formed with exactly 3 different integers are:
 * [1,2,1,3], [2,1,3], [1,3,4]
 */


#include<bits/stdc++.h>
using namespace std;

int atMost(vector<int> &arr, int k) {
    int l = 0, r= 0, cnt = 0;
    unordered_map<int, int> mpp;

    while (r < arr.size()) {
        mpp[arr[r]]++;

        while (mpp.size() > k) {
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0) mpp.erase(arr[l]);
            l++;
        }

        cnt += (r - l + 1);
        r++;
    }

    return cnt;
}

int subarrayWithKDistinct(vector<int> &arr,int k) {
    return atMost(arr, k) - atMost(arr, k-1);
}

int main() {

  vector<int> arr = {1, 2, 1, 3, 4};
  int k = 3;

  int res = subarrayWithKDistinct(arr, k);
  cout << res << endl;

  return 0;
}