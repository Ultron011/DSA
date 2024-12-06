/*
  Problem Statement: Merge Overlapping Subintervals
    You are given a list of n subintervals, where each subinterval is represented as a pair of integers [start, end]. 
    Each subinterval defines a range on the number line, where start is the beginning and end is the end (inclusive).
    Your task is to merge all overlapping subintervals into a new list such that no two subintervals overlap in the resulting list. 
    The merged list should be sorted in ascending order of start times.

    Input - 
      n = 5
      subintervals = [[1, 4], [2, 3], [5, 7], [6, 8], [9, 10]]
    
    Output - 
      [[1, 4], [5, 8], [9, 10]]
    
    Explanation:
      The subintervals [1, 4] and [2, 3] overlap, merging into [1, 4].
      The subintervals [5, 7] and [6, 8] overlap, merging into [5, 8].
      The subinterval [9, 10] does not overlap with any others.
*/

/*
  Time Complexity - 
      O(n log(n)) + O(2n)

  Space Complexity -
      O(n)

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeSubIntervals(vector<vector<int>>&arr) {
  int n = arr.size();
  sort(arr.begin(), arr.end());
  vector<vector<int>> ans;

  for (int i = 0; i < n; i++) {
    int start = arr[i][0];
    int end = arr[i][1];

    if (!ans.empty() && end <= ans.back()[1]) {
      continue;
    }
    for (int j = i + 1; j < n; j++) {
      if (arr[j][0] <= end) {
        end = max(end, arr[j][1]);
      } else {
        break;
      }
    }
    ans.push_back({start, end});
  }

  return ans;
}

int main() {

  vector<vector<int>> arr= {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};

  vector<vector<int>> ans = mergeSubIntervals(arr);

  for (auto it : ans) {
    cout << "[ ";
    for (int ele : it) {
      cout << ele << " ";
    }
    cout << "]\n";
  }

  return 0;
}