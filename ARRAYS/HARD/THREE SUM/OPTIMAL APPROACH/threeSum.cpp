/*
    Problem Statement: 3Sum Problem
    Given an array nums of 𝑛 integers, write a function to find all unique triplets in the array which gives the sum of zero.

    Input - 
        nums = [-1, 0, 1, 2, -1, -4]

    Output - 
        [[-1, -1, 2], [-1, 0, 1]]

    Explanation:
        The unique triplets that sum up to 0 are [-1, -1, 2] and [-1, 0, 1].
*/

/*
    Time complexity - 
        O(n log(n)) * O(m*n)

    Space complexity -
        O(no. of unique triplet)
*/


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        int j = i + 1;
        int k = n-1;
        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k+1]) k--;
            }
        }
    }

    return ans;
    
}

int main() {

  vector<int> arr = {-1, 0, 1, 2, -1, -4};

  vector<vector<int>> ans = threeSum(arr);

  for (auto it : ans) {
    cout << "[ ";
    for (int ele : it) {
        cout << ele << " ";
    }  
    cout << "]" << endl;
  }

  return 0;
}