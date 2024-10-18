/*
    * * * * * 
    * * * * *
    * * * * *
    * * * * *
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row , col;
  cout << "Enter no. of rows and columns : ";
  cin >> row >> col;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        cout << "* ";
    }
    cout << "\n";
  }

  return 0;
}