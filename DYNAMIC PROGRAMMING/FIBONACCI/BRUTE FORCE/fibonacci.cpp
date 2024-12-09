/*
  Time complexity - 
    O(2^n)
  
  Space compleixty - 
    O(n)

*/

#include<bits/stdc++.h>
using namespace std;

long long fibo(int n) {
    if (n <= 2) return 1;
    
    return fibo(n-1) + fibo(n-2);
}

int main() {
  int n;
  cout << "Enter the position of the Fibonacci number: ";
  cin >> n;

  long long result = fibo(n);
  cout << "The " << n << "th fibonacci number is " << result << endl;  

  return 0;
}