/*
    1 1 1 1 1 
    2 2 2 2 2 
    3 3 3 3 3
    4 4 4 4 4
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row , col;
  cout << "Enter no. of rows and columns : ";
  cin >> row >> col;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        cout << i+1 << " ";
    }
    cout << "\n";
  }

  return 0;
}