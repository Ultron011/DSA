/**
 * Problem :
 * Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters.
 * 
 * Input: s = "eceba", k = 2
 * Output: 3
 * Explanation: The substring is "ece" with length 3.
 * 
 * Input: s = "aa", k = 1
 * Output: 2
 * Explanation: The substring is "aa" with length 2.
 *
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(N)

    Space complexity - O(1)
*/

int longestSubstring(string str , int k) {
    int n = str.size();

    int l = 0, r = 0, maxlen = 0;
    unordered_map<char, int> mpp;

    while (r < n) {
        mpp[str[r]]++;

        if (mpp.size() > k) {
            mpp[str[l]]--;
            if (mpp[str[l]] == 0) mpp.erase(str[l]);
            l++;
        }

        if (mpp.size() <= k) {
            maxlen = max(maxlen, r - l + 1);
        }
        r++;
    }

    return maxlen;
}

int main() {

  string str = "aaabbccd";
  int k = 2;

  int res = longestSubstring(str, k);
  cout << res << endl;

  return 0;
}