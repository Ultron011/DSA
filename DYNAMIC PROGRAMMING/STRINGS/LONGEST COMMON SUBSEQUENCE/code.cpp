#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(2^(m + n))
    Space Complexity - O(m+n)
*/
int lcs_recursion(int i, int j, string&a, string&b) {
    if (i < 0 || j < 0) return 0;

    if (a[i] == b[j]) return 1 + lcs_recursion(i-1, j-1, a, b);
    return max(lcs_recursion(i-1, j, a, b), lcs_recursion(i, j-1, a, b));
}


int lcs_memoized(int i , int j, string&a, string&b, vector<vector<int>>&memo) {
    if (i < 0 || j < 0) return 0;
    if (memo[i][j] != -1) return memo[i][j];

    if (a[i] == b[j]) return memo[i][j] = 1 +  lcs_memoized(i-1, j-1, a, b, memo);
    return memo[i][j] = max(lcs_memoized(i-1, j, a, b, memo), lcs_memoized(i, j-1, a, b, memo));
}

int lcs_tabulated(string&a, string&b) {
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for  (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int lcs_space_optimized(string&a, string&b) {
    int m = a.size();
    int n = b.size();

    vector<int> prev(n+1, 0), curr(n+1, 0);

    for(int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) {
                curr[j] = 1 + prev[j-1];
            }
            else {
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }

    return prev[n];
}

int main() {
  string text1 = "abcde", text2 = "ace";
  
    cout << lcs_recursion(text1.size() - 1, text2.size() - 1, text1, text2) << endl;

    vector<vector<int>> memo(text1.size(), vector<int>(text2.size(), -1));
    cout << lcs_memoized(text1.size()-1, text2.size()-1, text1, text2, memo) << endl;

    cout << lcs_tabulated(text1, text2) << endl;

    cout << lcs_space_optimized(text1, text2) << endl;

  return 0;
}