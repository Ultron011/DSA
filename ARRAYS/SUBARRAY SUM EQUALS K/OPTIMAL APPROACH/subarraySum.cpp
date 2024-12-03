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
        O(nlog(n))

    Space complexity - 
        O(n)

*/

#include<bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &arr, int target) {
    int n = arr.size();
    
    unordered_map<int, int> mpp;
    int preSum = 0;
    int cnt =0;

    mpp[0] = 1;

    for (int i = 0; i < n; i++) {
        preSum += arr[i];
        int complement = preSum - target;
        cnt += mpp[complement];
        mpp[preSum] += 1;
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