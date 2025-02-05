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
    Time complexity - O(n)

    Space complexity - O(n)
*/

// Using set 

int solve(string str) {
  int n = str.size();
  unordered_set<char> seen;
  int maxlen = 0;
  int l = 0, r = 0;
  
  while (r < n) {
    // Shrink the window if a repeating character is found
    while (seen.find(str[r]) != seen.end()) {
      seen.erase(str[l]);
      l++;  // Move the left pointer to the right
    }
    
    // Expand the window and update maxlen if no duplicate characters
    seen.insert(str[r]);
    maxlen = max(maxlen, r - l + 1);  // Update the maximum length
    r++;  // Move the right pointer to the right
  }

  return maxlen;
}

// Using hashmap

int solveUsingHash(string str) {
  int n = str.size();
  unordered_map<char, int> last_index;  // Map to store the last index of each character
  int maxlen = 0;
  int l = 0;  // Left pointer of the window
  
  for (int r = 0; r < n; r++) {  // r is the right pointer of the window
    // If the character at r is repeating, move the left pointer to the right of its last occurrence
    if (last_index.find(str[r]) != last_index.end()) {
      // Move left pointer to the right of the last occurrence of str[r]
      l = max(l, last_index[str[r]] + 1);
    }

    // Update the last index of str[r]
    last_index[str[r]] = r;
    
    // Update maxlen with the current window size
    maxlen = max(maxlen, r - l + 1);
  }

  return maxlen;
}

int main() {
  string str = "takeUforward";
  cout << "The length of the longest substring without repeating characters is " << 
  solve(str);
  return 0;
}