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
    Time complexity - O(n)
    
    Space complexity - O(1)
        
*/

int nthRootOfM(int n, int m) {
    for (int i = 1; i <= m; i++) {
        int power = pow(i, n);
        if (power == m) {
            return i;
        }
        else if(power> m) {
            break;
        }
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