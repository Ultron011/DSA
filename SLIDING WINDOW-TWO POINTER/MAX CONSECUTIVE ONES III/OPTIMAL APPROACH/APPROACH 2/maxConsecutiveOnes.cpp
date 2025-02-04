/**
 * LeetCode Problem 1004: Max Consecutive Ones III
 *
 * Problem Statement:
 * Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
 *
 * Input:
 * - nums: A binary array (an array consisting of only 0s and 1s).
 * - k: An integer representing the maximum number of 0's you can flip.
 *
 * Output:
 * - An integer representing the maximum number of consecutive 1's in the array after flipping at most k 0's.
 *
 * Explanation:
 * You are allowed to flip at most k 0's to 1's in the given binary array. The goal is to find the longest subarray that contains only 1's after performing the flips.
 *
 * Example:
 * Input: nums = [1,1,0,0,1,1,1,0,1,1,1], k = 2
 * Output: 8
 * Explanation: Flip the 0's at indices 2 and 3 to get the array [1,1,1,1,1,1,1,0,1,1,1], which has 8 consecutive 1's.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(2n)

    Space complexity - O(1)
*/

int maxConsecutiveOnes(vector<int>& nums, int k) {
    int n = nums.size();
    
    int l = 0, r = 0, zeros = 0, maxlen = 0;

    while ( r < n) {
        if (nums[r] == 0) zeros++;

        while (zeros > k) {
            if (nums[l] == 0) zeros--;
            l++;
        }

        maxlen = max(maxlen, r - l +1);
        r++;
    }

    return maxlen;
}

int main() {

  vector<int>  nums = {1,1,0,0,1,1,1,0,1,1,1};
  int k = 2;

  int ans = maxConsecutiveOnes(nums, k);
  cout << ans << endl;

  return 0;
}