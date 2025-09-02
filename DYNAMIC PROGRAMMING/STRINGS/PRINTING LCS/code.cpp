#include<bits/stdc++.h>
using namespace std;

void lcs(string&a, string&b, vector<vector<int>> &dp) {
    int m = a.size();
    int n = b.size();

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
}

int main() {
  string text1 = "abcde", text2 = "bdgek";
    int m = text1.size();
    int n = text2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    lcs(text1, text2, dp);

    int len = dp[m][n];
    string ans = "";
    for (int i = 0; i < len; i++) {
        ans += '$';
    }

    int index = len - 1;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (text1[i-1] == text2[j-1]) {
            ans[index] = text1[i-1];
            index--;
            i--, j--;
        } 
        else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }

    cout << ans << endl;

  return 0;
}