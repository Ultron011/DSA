#include<bits/stdc++.h>
using namespace std;

// Naive recursive approach - O(2^n) time complexity
int solve(int n) {
    if (n == 1 || n == 0) return 1;
    if (n < 0) return 0;

    int ways = solve(n-1) + solve(n-2);
    return ways;
}


/*
    T.C - O(n)
    S.C - O(n)
*/
long long memoSolve(int n, vector<long long> &memo) {
    if (n < 0) return 0;                  
    if (n == 0 || n == 1) return 1;        

    if (memo[n] != -1) return memo[n];      

    memo[n] = memoSolve(n-1, memo) + memoSolve(n-2, memo);
    return memo[n];
}

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    vector<long long> memo(n+1, -1);

    // cout << solve(n);
    cout << memoSolve(n, memo);

  return 0;
}