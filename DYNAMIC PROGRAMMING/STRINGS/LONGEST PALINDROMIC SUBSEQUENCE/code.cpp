#include<bits/stdc++.h>
using namespace std;


/*
    Time complexity - O(m*n)
    Space complexity - O(n)
*/
int lps(string&s) {
    string t = s;
    reverse(t.begin(), t.end());

    int n = s.size();
    
    vector<int> prev(n+1, 0), curr(n+1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == t[j-1]) {
                curr[j] = 1 + prev[j-1];
            } else {
                curr[j] = max(curr[j-1], prev[j]);
            }
        }
        prev = curr;
    }

    return prev[n];
}

int main() {
  string s = "bbabcbcab";
  
  cout << lps(s) << endl;
  return 0;
}