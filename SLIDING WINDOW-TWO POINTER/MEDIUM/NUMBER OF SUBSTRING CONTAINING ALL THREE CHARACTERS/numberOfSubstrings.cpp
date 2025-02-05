/**
 * LeetCode Problem 1358: Number of Substrings Containing All Three Characters
 *
 * Problem Statement:
 * Given a string s consisting only of characters a, b, and c.
 * Return the number of substrings containing at least one occurrence of all these characters a, b, and c.
 *
 * Example 1:
 * Input: s = "abcabc"
 * Output: 10
 * Explanation: The substrings containing at least one occurrence of the characters a, b, and c are:
 * "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc", "abc"
 *
 * Example 2:
 * Input: s = "aaacb"
 * Output: 3
 * Explanation: The substrings containing at least one occurrence of the characters a, b, and c are:
 * "aaacb", "aacb", "acb"
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(N)

    Space complexity - O(1)
*/

int numberOfSubstrings(string str) {
    vector<int> lastSeen(3, -1);
    int n = str.size();
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        lastSeen[str[i] - 'a'] = i;

        cnt = cnt + (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
    }

    return cnt;
}

int main() {

  string str = "bbacba";
  
  int res = numberOfSubstrings(str);
  cout << res << endl;

  return 0;
}