/*
    1
    2 2 
    3 3 3
    4 4 4 4
    5 5 5 5 5
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  cout << "Enter no. of rows : ";
  cin >> row;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j <= i; j++) {
        cout << i+1 << " ";
    }
    cout << "\n";
  }

  return 0;
}