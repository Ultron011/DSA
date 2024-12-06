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
        O(n^3 * log(m)) (m - no. of elements in hashset)

    Space complexity -
        O(n) + 2 * O(no. of quads) 

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> arr, int target) {
    int n= arr.size();
    set<vector<int>> st;
    
    for (int i = 0; i < n; i++) {
        for (int j= i+1; j < n; j++) {
            set<long long> hashset;
            for (int k = j +1; k < n; k++) {
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {arr[i], arr[j], arr[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
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