/*
    Problem Statement: 
        You are given a positive integer n. Your task is to find and return its square root. 
        If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

        Input Format:
            n = 36
        Result:
            6
        Explanation:
            6 is the square root of 36.

        Input Format:
        n = 28
        Result:
        5
        Explanation:
        Square root of 28 is approximately 5.292. So, the floor value will be 5.
*/

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(n)
    
    Space complexity - O(1)
        
*/

int squareRoot(int n) {
    int low = 0, high = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int square = mid * mid;

        if (square <= n) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}

int main() {

  int n;
  cout << "Enter the number : ";
  cin >> n;

  int res = squareRoot(n);
  cout << "Square root of " << n << " is : " << res << endl;

  return 0;
}