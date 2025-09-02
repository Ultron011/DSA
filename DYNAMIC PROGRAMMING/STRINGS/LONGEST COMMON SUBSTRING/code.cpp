#include<bits/stdc++.h>
using namespace std;


/*
    Time complexity - O(m*n)
    Space complexity - O(m+n)
*/
int lcs_tabulated(string&a, string&b) {
  int n = a.size();
  int m = b.size();
  vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

  int ans = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <=m; j++) {
        if (a[i-1] == b[j-1]) {
            dp[i][j] = 1 + dp[i-1][j-1];
            ans = max(ans, dp[i][j]);
        } else {
            dp[i][j] = 0;
        }
    }
  }

  return ans;
}

/*
    Time complexity - O(m*n)
    Space complexity - O(n)
*/
int lcs_space_optimized(string&a, string&b) {
    int n = a.size();
    int m = b.size();

    vector<int> prev(m+1, 0), curr(m+1, 0);
    int ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                curr[j] = 1 + prev[j-1];
                ans = max(ans, curr[j]);
            } else {
                curr[j] = 0;
            }
        }
        prev = curr;
    }

    return ans;
}


int main() {
  string a = "adac", b = "adadac";


  cout << "Length of Longest common substring is : " << lcs_tabulated(a, b) << endl;
  cout << "Length of Longest common substring is : " << lcs_space_optimized(a, b) << endl;

  return 0;
}