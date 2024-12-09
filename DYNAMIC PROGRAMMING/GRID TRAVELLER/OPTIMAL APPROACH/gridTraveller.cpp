/*
  Time complexity - 
    O(2^n+m)
  
  Space compleixty - 
    O(n+m)

*/

#include<bits/stdc++.h>
using namespace std;

long long gridTraveller(int m, int n, unordered_map<string, long long>& memo) {
    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;

    // Create a unique key as "m,n"
    string key = to_string(m) + "," + to_string(n);

    // Check if the result is already computed
    if (memo.find(key) != memo.end()) {
      return memo[key];
    }

    memo[key] = gridTraveller(m, n-1, memo) + gridTraveller(m-1, n, memo);
    return memo[key];
}

int main() {

  int m, n;
  cout <<  "Enter the dimensions of the grid (m * n) : ";
  cin >> m >> n;

  unordered_map<string , long long> memo;
  long long result = gridTraveller(m, n, memo);
  cout << "Number of Ways to travel in a " << m << "*" << n << " grid is " << result << endl;

  return 0;
}