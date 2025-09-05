#include<bits/stdc++.h>
using namespace std;

int numDistinctRecursive(string s, string t, int i, int j) {
    if (j == 0) return 1;           // t is empty
    if (i == 0) return 0;           // s is empty but t is not

    if (s[i - 1] == t[j - 1])
        return numDistinctRecursive(s, t, i - 1, j - 1) + numDistinctRecursive(s, t, i - 1, j);
    else
        return numDistinctRecursive(s, t, i - 1, j);
}

int numDistinctMemoized(string&s, string&t, int i, int j, vector<vector<int>>&memo) {
    if (j == 0) return 1;
    if (i == 0) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    if (s[i-1] == t[j-1]) {
        return memo[i][j] = numDistinctMemoized(s, t, i-1, j-1, memo) + numDistinctMemoized(s, t, i - 1, j, memo);
    }
    else {
        return memo[i][j] = numDistinctMemoized(s, t, i -1, j, memo);
    }

    return memo[i][j];
}

int numDistinctTabulated(string&s, string&t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return (int)dp[n][m];
}

int numDistinctSpaceOptimized_v1(string&s, string&t) {
    int n = s.size();
    int m = t.size();

    vector<int> prev(m+1, 0), curr(m+1, 0);

    prev[0] = 1, curr[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                curr[j] = prev[j-1] + prev[j];
            } else {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }

    return (int)prev[m];
}

int numDistinctSpaceOptimized_v2(string&s, string&t) {
    int n = s.size();
    int m = t.size();

    vector<int> prev(m+1, 0);

    prev[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (s[i-1] == t[j-1]) {
                prev[j] = prev[j-1] + prev[j];
            }
        }
    }

    return (int)prev[m];
}

int main() {
  string s = "rabbbit", t = "rabbit";
  
  cout << numDistinctRecursive(s, t, s.size(), t.size()) << endl;

  vector<vector<int>> memo(s.size() + 1, vector<int>(t.size() + 1, -1));
  cout << numDistinctMemoized(s, t, s.size(), t.size(), memo) << endl;

  cout << numDistinctTabulated(s, t) << endl; 

  cout << numDistinctSpaceOptimized_v1(s, t) << endl;

  cout << numDistinctSpaceOptimized_v2(s, t) << endl;

  return 0;
}