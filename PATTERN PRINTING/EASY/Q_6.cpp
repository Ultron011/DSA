/*
    a b c d e
    a b c d e
    a b c d e
    a b c d e
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row , col;
  cout << "Enter no. of rows and columns : ";
  cin >> row >> col;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        char c = 'a' + j;
        cout << c << " ";
    }
    cout << "\n";
  }

  return 0;
}