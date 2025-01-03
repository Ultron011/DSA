/**
 * Problem - Split Array Largest Sum
 * 
 * Given an array of non-negative integers and an integer m, you need to split the array into m non-empty continuous subarrays.
 * Write a function to minimize the largest sum among these m subarrays.
 * 
 * Input: nums = [7, 2, 5, 10, 8], m = 2
 * Output: 18
 * Explanation: There are four ways to split nums into two subarrays.
 * The best way is to split it into [7, 2, 5] and [10, 8], where the largest sum among the two subarrays is minimized to 18.
 * 
 * Input: nums = [1, 2, 3, 4, 5], m = 2
 * Output: 9
 * Explanation: There are several ways to split nums into two subarrays.
 * The best way is to split it into [1, 2, 3, 4] and [5], where the largest sum among the two subarrays is minimized to 9.
 */

#include<bits/stdc++.h>
using namespace std;

int countPartitions(vector<int> &a, int maxSum) {
    int n = a.size(); //size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + a[i] <= maxSum) {
            //insert element to current subarray
            subarraySum += a[i];
        }
        else {
            //insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}

int largestSubarraySumMinimized(vector<int> &a, int k) {
    int low = *max_element(a.begin(), a.end());
    int high = accumulate(a.begin(), a.end(), 0);

    int n = a.size();
    if (k > n) return -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (countPartitions(a, mid) <= k) high = mid  - 1;
        else low = mid + 1;
    }
    return low;
}

int main()
{
    vector<int> a = {10, 20, 30, 40};
    int k = 2;
    int ans = largestSubarraySumMinimized(a, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}