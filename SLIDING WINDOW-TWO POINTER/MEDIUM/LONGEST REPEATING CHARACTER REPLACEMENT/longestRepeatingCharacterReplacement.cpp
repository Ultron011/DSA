/*
 * Problem: Leetcode 424 - Longest Repeating Character Replacement
 * 
 * Given a string s that consists of only uppercase English letters, you can perform at most k operations on that string. 
 * In one operation, you can choose any character of the string and change it to any other uppercase English character.
 * 
 * Your task is to find the length of the longest substring containing the same letter you can get after performing the above operations.
 * 
 * Example 1:
 * Input: s = "ABAB", k = 2
 * Output: 4
 * Explanation: Replace the two 'A's with two 'B's or vice versa to get "BBBB" or "AAAA".
 * 
 * Example 2:
 * Input: s = "AABABBA", k = 1
 * Output: 4
 * Explanation: Replace the one 'A' in the middle with 'B' to get "AABBBBA".
 * 
 * Constraints:
 * - 1 <= s.length <= 10^5
 * - s consists of only uppercase English letters.
 * - 0 <= k <= s.length
 */

#include<bits/stdc++.h>
using namespace std;

/*
  Time complexity - O(N)

  Space complexity - O(1)
*/

int characterReplacement(string s, int k) {
    int l = 0, r= 0, maxlen = 0, maxf = 0;

    unordered_map<char,  int> freq;

    while (r < s.length()) {
      freq[s[r]]++;
      maxf = max(maxf, freq[s[r]]);

      if ((r-l+1) - maxf > k) {
        freq[s[l]]--;
        l++;
      }

      maxlen = max(maxlen, r -l + 1);
      r++;
    }

    return maxlen;
}


int main() {

  string str = "AABABBA";
  int k = 1;

  int res = characterReplacement(str, k);
  cout << res << endl;

  return 0;
}