/**
 * LeetCode Problem 930: Binary Subarrays With Sum
 *
 * Problem Statement:
 * Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum equal to goal.
 *
 * Sample Input:
 * nums = [1,0,1,0,1], goal = 2
 *
 * Sample Output:
 * 4
 *
 * Explanation:
 * The 4 subarrays are:
 * - [1,0,1] with sum 2
 * - [0,1,0,1] with sum 2
 * - [1,0,1] with sum 2
 * - [1,0,1,0] with sum 2
 */

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int goal) {

    int l = 0, r = 0, sum = 0, cnt = 0;

    while (r < arr.size()) {
        sum += arr[r];

        while (sum > goal) {
            sum -= arr[l];
            l++;
        }

        cnt += (r - l + 1);
        r++;
    } 
    return cnt;
}

int numSubarraysWithSum(vector<int> &arr, int goal) {
    if (goal < 0) return 0;

    int f1 = solve(arr, goal);
    int f2 = solve(arr, goal - 1);

    return f1 - f2;
}

int main() {

  vector<int> arr= {1,0,1,0,1};
  int goal = 2;

  int res = numSubarraysWithSum(arr, goal);
  cout << res << endl;

  return 0;
}