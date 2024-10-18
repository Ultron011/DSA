/*
    5 4 3 2 1
    5 4 3 2 1
    5 4 3 2 1
    5 4 3 2 1
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row , col;
  cout << "Enter no. of rows and columns : ";
  cin >> row >> col;

  for (int i = 0; i < row; i++) {
    for (int j = col; j > 0; j--) {
        cout << j  << " ";
    }
    cout << "\n";
  }

  return 0;
}