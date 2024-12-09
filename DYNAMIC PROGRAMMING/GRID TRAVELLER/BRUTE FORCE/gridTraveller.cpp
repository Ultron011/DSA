/*
  Time complexity - 
    O(2^n+m)
  
  Space compleixty - 
    O(n+m)

*/

#include<bits/stdc++.h>
using namespace std;

int gridTraveller(int m, int n) {
    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;

    int ways = gridTraveller(m, n-1) + gridTraveller(m-1, n);
    return ways;
}

int main() {

  int m, n;
  cout <<  "Enter the dimensions of the grid (m * n) : ";
  cin >> m >> n;

  cout << gridTraveller(m, n) << endl;

  return 0;
}