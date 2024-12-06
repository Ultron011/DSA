/*

    Problem Statement: Longest Consecutive Subsequence (LCSq)
    The Longest Consecutive Subsequence problem requires finding the length of the longest subsequence of 
    consecutive integers (not necessarily contiguous) in an unsorted array.

    Input - 
        N = 7
        arr = [2, 6, 1, 9, 4, 5, 3]

    Output:
        6

    Explanation -
        The longest consecutive subsequence is [1, 2, 3, 4, 5, 6], which has a length of 6.

*/

/*
    Time complexity - 
        O(n)
    
    Space complexity - 
        O(n)
*/

#include<bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(vector<int> &arr) {
    int n = arr.size();
    if (n == 0) return 0;
    unordered_set<int> st;
    int longest = 1;
    for (int i = 0; i < n; i++) {
        st.insert(arr[i]);
    }
    
    for (auto it : st) {
        if (st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main() {

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int lcs = longestCommonSubsequence(arr);
  cout << "The longest common subsequence is of length : " << lcs << endl;

  return 0;
}