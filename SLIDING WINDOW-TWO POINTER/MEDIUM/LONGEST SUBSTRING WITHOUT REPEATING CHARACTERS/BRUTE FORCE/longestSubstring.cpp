/* Given a string s, find the length of the longest substring without repeating characters.

   Example 1:

   Input: s = "abcabcbb"
   Output: 3
   Explanation: The answer is "abc", with the length of 3.

   Example 2:

   Input: s = "bbbbb"
   Output: 1
   Explanation: The answer is "b", with the length of 1. */


#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(n^2)

    Space complexity - O(n)
*/

int solve(string str) {
  int n  = str.size();
  int maxlen = 0;
  for (int i = 0; i < n; i++) {
    unordered_set<char> seen;
    for (int j = i; j < n; j++) {
      if (seen.find(str[j]) != seen.end()) break;
      
      int len = j - i + 1;
      maxlen = max(len, maxlen);
      seen.insert(str[j]);
    }
  }

  return maxlen;
}

int main() {
  string str = "takeUforward";
  cout << "The length of the longest substring without repeating characters is " << 
  solve(str);
  return 0;
}