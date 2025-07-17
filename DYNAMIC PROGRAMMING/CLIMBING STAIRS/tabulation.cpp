#include<bits/stdc++.h>
using namespace std;

/*
    T.C - O(n)
    S.C - O(n)
*/
int tabulatedClimbStairs(int n) {
    if (n < 0) return 0;                  
    if (n == 0 || n == 1) return 1; 
    
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-2] + dp[i-1];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    cout << tabulatedClimbStairs(n);

  return 0;
}