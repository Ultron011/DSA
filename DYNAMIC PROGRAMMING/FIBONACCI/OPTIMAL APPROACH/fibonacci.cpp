/*
  Time complexity - 
    O(2*n)
  
  Space compleixty - 
    O(n)

*/

#include<bits/stdc++.h>
using namespace std;

long long fibo(int n, unordered_map<int, long long>& memo) {
    if (n <= 2) return 1;
    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    memo[n] = fibo(n-1, memo) + fibo(n-2, memo);
    return memo[n];
}

int main() {
  int n;
  cout << "Enter the position of the Fibonacci number: ";
  cin >> n;

  // Create a memoization table 
  unordered_map<int, long long> memo;
  long long result = fibo(n, memo);
  cout << "The " << n << "th fibonacci number is " << result << endl;  

  return 0;
}