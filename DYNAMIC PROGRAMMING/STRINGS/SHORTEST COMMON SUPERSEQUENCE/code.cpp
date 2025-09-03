#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(n * m)
    Space Complexity: O(n * m)
    where n and m are the lengths of the input strings a and b
*/
string shortestCommonSupersequence(string&a, string&b) {
    int n = a.size();
    int m = b.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    // Create the DP Table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    // Build the supersequence
    string ans;
    int i = n,  j = m;
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            ans += a[i-1];
            i--, j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            ans += a[i-1];
            i--;
        } else {
            ans += b[j-1];
            j--;
        }
    }
    while (i > 0) {
        ans += a[i-1];
        i--;
    }
    while (j > 0) {
        ans += b[j-1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
  string s1 = "abac", s2="cab";
  
  string ans = shortestCommonSupersequence(s1, s2) ;
  cout << ans << endl;

  return 0;
}