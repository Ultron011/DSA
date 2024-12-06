/*
    a a a a a 
    b b b b b 
    c c c c c
    d d d d d
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row , col;
  cout << "Enter no. of rows and columns : ";
  cin >> row >> col;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        char c = 'a' + i;
        cout << c << " ";
    }
    cout << "\n";
  }

  return 0;
}