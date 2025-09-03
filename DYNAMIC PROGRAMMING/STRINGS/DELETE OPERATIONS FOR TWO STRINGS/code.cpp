#include<bits/stdc++.h>
using namespace std;

int minDistance(string&a, string&b) {
    int n = a.size();
    int m = b.size();
    vector<int> prev(m+1, 0), curr(m+1, 0);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                curr[j] = 1 + prev[j-1];
            } else {
                curr[j] = max(prev[j], curr[j-1]);
            }
        }
        prev = curr;
    }

    int lcs_len = prev[m];
    return n + m - 2 * lcs_len;
}

int main() {
  string a = "sea", b = "eat";
   
  cout << "Min Operartion to make both strings same: " << minDistance(a, b) << endl;

  return 0;
}