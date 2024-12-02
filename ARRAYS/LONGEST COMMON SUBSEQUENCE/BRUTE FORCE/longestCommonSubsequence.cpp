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
        O(n^2)
    
    Space complexity - 
        O(1)
*/


#include<bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            return true;
        }
    }
    return false;
}

int longestCommonSubsequence(vector<int> &arr) {
    if (arr.size() == 0) return 0;
    int longest = 1;
    for (int i = 0; i < arr.size(); i++) {
        int x = arr[i];
        int cnt = 1;
        while (linearSearch(arr, x+1)) {
            x++;
            cnt++;
        }
        longest = max(cnt, longest);
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