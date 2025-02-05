/**
 * LeetCode Problem 1248: Count Number of Nice Subarrays
 *
 * Problem Statement:
 * Given an array of integers nums and an integer k. A subarray is called nice if there are k odd numbers on it.
 * Return the number of nice subarrays.
 *
 * Example 1:
 * Input: nums = [1,1,2,1,1], k = 3
 * Output: 2
 * Explanation: The subarrays [1,1,2,1] and [1,2,1,1] have exactly 3 odd numbers.
 *
 * Example 2:
 * Input: nums = [2,4,6], k = 1
 * Output: 0
 * Explanation: There is no subarray with exactly 1 odd number.
 *
 * Example 3:
 * Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
 * Output: 16
 * Explanation: The subarrays that have exactly 2 odd numbers are:
 * [2,2,2,1,2], [2,2,1,2,2], [2,1,2,2,2], [1,2,2,2,2], [2,2,1,2], [2,1,2,2], [1,2,2,2], [2,2,2,1,2,2], [2,2,1,2,2], [2,1,2,2,2], [1,2,2,2,2], [2,2,1,2,2], [2,1,2,2,2], [1,2,2,2,2], [2,2,1,2,2], [2,1,2,2,2].
 */

#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int goal) {

    int l = 0, r = 0, sum = 0, cnt = 0;

    while (r < arr.size()) {
        sum += arr[r] % 2;

        while (sum > goal) {
            sum -= arr[l] % 2;
            l++;
        }

        cnt += (r - l + 1);
        r++;
    } 
    return cnt;
}

int numSubarraysWithSum(vector<int> &arr, int k) {

    int f1 = solve(arr, k);
    int f2 = solve(arr, k - 1);

    return f1 - f2;
}

int main() {

  vector<int> arr= {2,2,2,1,2,2,1,2,2,2};
  int k = 2;

  int res = numSubarraysWithSum(arr, k);
  cout << res << endl;

  return 0;
}