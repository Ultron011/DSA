/*
    Problem Statement: Four Sum
        Given an array of integers nums and an integer target, find all unique quadruplets [a, b, c, d] in the array such that:
        a+b+c+d=target


    Input - 
        nums = [1, 0, -1, 0, -2, 2]
        target = 0

    Output -
        [[ -2, -1, 1, 2], [-2, 0, 0, 2], [-1, 0, 0, 1]]

*/

/*
    Time complexity -
        O(n^3)

    Space complexity -
        O(no. of quads) 

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> arr, int target) {
    int n= arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i-1]) continue;
        for (int j = i+1; j < n; j++) {
            if (j != i+1 && arr[j] == arr[j-1]) continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if (sum == target) {
                    vector<int> temp = {arr[i], arr[j], arr[k],arr[l]};
                    ans.push_back(temp);
                    k--;
                    l--;
                    while (k < l && arr[k] == arr[k-1]) k++;
                    while (k < l && arr[l] == arr[l+1]) l--;
                } 
                else if ( sum < target) {
                    k++;
                } else {
                    l--;
                }
            }
        }
    }
    return ans;
}

int main() {

  vector<int> arr = {1, 0, -1, 0, -2, 2};
  int target;
  cout << "Enter the target : ";
  cin >> target;

  vector<vector<int>> ans = fourSum(arr, target);

  for (auto it : ans) {
    cout << "[ ";
    for (int ele : it) {
        cout << ele << " ";
    }
    cout << "]\n";
  }
  return 0;
}