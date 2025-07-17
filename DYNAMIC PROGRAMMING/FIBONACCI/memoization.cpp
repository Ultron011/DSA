#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;


/*
    T.C - O(n)
    S.C - O(n)
*/
long long fib(int n, vector<long long> &memo) {
    if (n == 0 || n == 1) return n;

    if (memo[n] != -1) return memo[n];

    memo[n] = (fib(n-1, memo) + fib(n-2, memo)) % MOD;
    return memo[n];
}

/*
    T.C - O(n)
    S.C - O(n)
*/
long long fibNoRecursion(int n) {
    if (n == 0 || n == 1) return n;

    vector<long long> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    return dp[n];

}


int main() {
    
    int n;
    cout << "Enter : ";
    cin >> n;

    vector<long long> memo(n+1, -1);
    cout << fib(n, memo) << endl;


  return 0;
}