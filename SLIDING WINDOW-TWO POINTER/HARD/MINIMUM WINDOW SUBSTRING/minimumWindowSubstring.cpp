/**
 * LeetCode Problem 76: Minimum Window Substring
 *
 * Problem Statement:
 * Given two strings `s` and `t` of lengths `m` and `n` respectively, return the minimum window substring of `s` such that every character in `t` (including duplicates) is included in the window. If there is no such substring, return the empty string "".
 *
 * The test cases will be generated such that the answer is unique.
 *
 * Sample Input:
 * s = "ADOBECODEBANC", t = "ABC"
 *
 * Sample Output:
 * "BANC"
 *
 * Explanation:
 * The minimum window substring "BANC" includes 'A', 'B', and 'C' from string `t`.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(2n + m);

    Space complexity - O(1)
*/

string minWindow(string s, string t) {
    int n = s.size();
    int m = t.size();
    int l = 0, r= 0, cnt= 0, minLen = INT_MAX, sIndex = -1;
    vector<int> hash(256, 0);
    for (char c : t) hash[c]++;

    while (r < n) {
        if (hash[s[r]] > 0) cnt++;
        hash[s[r]]--;

        while (cnt == m) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                sIndex = l;
            }
            hash[s[l]]++;
            if (hash[s[l]] > 0) cnt--;
            l++;
        }
        r++;
    }
    return minLen == INT_MAX ? "" : s.substr(sIndex, minLen);

}

int main() {

  string s = "ADOBECODEBANC";
  string t = "ABC";

  string res = minWindow(s, t);
  cout << res << endl;

  return 0;
}