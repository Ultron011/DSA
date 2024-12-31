/**
 * Problem Statement:
 * ------------------
 * Given two integers N and M, find the Nth root of M. The Nth root of M is a number X such that X^N = M.
 * If such a number X exists, return it. If there are multiple such numbers, return the smallest one.
 * If no such number exists, return -1.
 *
 * Sample Input:
 * -------------
 * N = 3, M = 27
 *
 * Sample Output:
 * --------------
 * 3
 *
 * Sample Input:
 * -------------
 * N = 2, M = 10
 *
 * Sample Output:
 * --------------
 * -1
 *
 * Explanation:
 * ------------
 * There is no integer X such that X^2 = 10.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(nlog(m))
    
    Space complexity - O(1)
        
*/

/*
    0 --> < m
    1 --> == m
    2 --> > m
*/

// Helper function to calculate mid^n and check if it equals m.
int func(int mid, int n, int m) {
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= mid;
        // Check for overflow or if the result exceeds m
        if (ans > m) return 2;
    }
    if (ans == m) return 1;
    return 0;
}

int nthRootOfM(int n, int m) {
    if (m == 1) return 1; // Special case: any root of 1 is 1
    int low = 1, high = m;
    while (low <= high) {
        int mid = low + (high - low) / 2;  // Safe way to compute mid
        int midN = func(mid, n, m);
        
        if (midN == 1) return mid; 
        else if (midN == 0) low = mid + 1;
        else high = mid - 1; 
    }
    return -1;
}

int main() {

   int n, m;
   cout << "Enter n and m : ";
   cin >> n >> m;

   int res = nthRootOfM(n, m);
   cout << n << "th root of " << m << " is: " << res << endl;
  

  return 0;
}