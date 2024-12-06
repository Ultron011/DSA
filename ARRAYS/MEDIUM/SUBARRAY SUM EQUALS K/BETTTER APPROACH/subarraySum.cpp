/*
    Problem Statement: Count Subarray Sum Equals 𝑘
        Given an array of integers nums and an integer k, 
        write a function to find the total number of continuous subarrays whose sum equals 𝑘.

    Input -
        nums = [1, 2, 3]
        k = 3

    Output -
        2

    Explanation -
        The subarrays are [1, 2] and [3].
*/

/*
    Time complexity - 
        O(n^2)

    Space complexity - 
        O(1)

*/


#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &arr, int target) {
    int n = arr.size();
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == target) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {

  vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
  int target;
  cin >> target;

  cout << "Number of Subarrays with sum " << target << " is : " << subarraySum(arr, target) << endl;

  return 0;
}