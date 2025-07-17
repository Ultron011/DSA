#include<bits/stdc++.h>
using namespace std;

/*
    T.C - O(n)
    S.C - O(1)
*/
int climbStairs(int n) {
    if (n == 1 || n == 0) return 1;
    if (n < 0) return 0;

    int p2 = 1, p1 = 1;
    for (int i = 2; i <= n; i++) {
        int res = p1 + p2;
        p1 = p2;
        p2 = res;
    }

    return p2;
}


int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    cout << climbStairs(n);

  return 0;
}