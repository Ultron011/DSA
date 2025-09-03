#include<bits/stdc++.h>
using namespace std;

int minInsertions(string&s) {
    int n = s.size();
    string t = s;
    reverse(t.begin(), t.end());

    vector<int> prev(n+1 , 0) , curr(n+1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == t[j-1]) {
                curr[j] = 1 + prev[j-1];
            } else {
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }

    int lcs_len = prev[n];
    return n - lcs_len;
}

int main() {
  string s = "abcaa";
  
  cout << "Min insertions required to make string palindrome : " << minInsertions(s) << endl;

  return 0;
}