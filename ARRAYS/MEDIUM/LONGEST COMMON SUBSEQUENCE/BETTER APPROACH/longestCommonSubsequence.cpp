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
        O(nlog(n))
    
    Space complexity - 
        O(1)
*/


#include<bits/stdc++.h>
using namespace std;


int longestCommonSubsequence(vector<int> &arr) {
    if (arr.size() == 0) return 0;
    sort(arr.begin(), arr.end());

    int longest = 1;
    int last_smaller = INT_MIN;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (last_smaller == arr[i] - 1) {
            cnt += 1;
            last_smaller = arr[i];
        }
        else if (last_smaller != arr[i]) {
            cnt = 1;
            last_smaller = arr[i];
        }
        longest = max(longest, cnt);
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