#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;


/*
    T.C - O(n)
    S.C - O(1)
*/

long long fib(int n) {
    if (n == 0 || n == 1) return n;

    long long prev2 = 0, prev1 = 1;
    long long res = 0;

    for (int i = 2; i <= n; i++) {
        res = (prev2 + prev1) % MOD;
        prev2 = prev1;
        prev1 = res;
    }

    return res;
}


int main() {
    
    int n;
    cout << "Enter : ";
    cin >> n;

    cout << fib(n) << endl;


  return 0;
}