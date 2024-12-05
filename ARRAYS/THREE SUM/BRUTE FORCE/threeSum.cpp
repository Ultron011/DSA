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
        O(n^3*log(no. of unique triplets))

    Space complexity -
        2*O(no. of triplets)
*/


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &arr) {
    int n = arr.size();
    set<vector<int>> st;
    for (int i =0; i < n; i++) {
        for (int j= i+1; i < n; i++) {
            for (int k = j+1; j < n; j++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
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