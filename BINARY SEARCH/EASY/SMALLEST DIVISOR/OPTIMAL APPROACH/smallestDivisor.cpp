/**
 * Problem: Smallest Divisor Given a Threshold
 * 
 * Given an array of integers `nums` and an integer `threshold`, we need to find the smallest integer `divisor` such that the result of summing up the division of each element in the array by the divisor is less than or equal to the threshold. The division result should be rounded up to the nearest integer.
 * 
 * Example:
 * 
 * Input:
 * nums = [1, 2, 5, 9]
 * threshold = 6
 * 
 * Output:
 * 5
 * 
 * Explanation:
 * When the divisor is 5, the division results are:
 * - 1 / 5 = 1
 * - 2 / 5 = 1
 * - 5 / 5 = 1
 * - 9 / 5 = 2
 * 
 * Summing these results: 1 + 1 + 1 + 2 = 5, which is less than or equal to the threshold 6.
 * 
 * If we try a smaller divisor, the sum would exceed the threshold. For example, with divisor 4:
 * - 1 / 4 = 1
 * - 2 / 4 = 1
 * - 5 / 4 = 2
 * - 9 / 4 = 3
 * 
 * Summing these results: 1 + 1 + 2 + 3 = 7, which is greater than the threshold 6.
 */

#include<bits/stdc++.h>
using namespace std;

int sumByD(vector<int> &arr, int div) {
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

int smallestDivisor(vector<int> &arr, int limit) {
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());

    int low = 1, high = maxi;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (sumByD(arr, mid) <= limit) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;

}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";

  return 0;
}