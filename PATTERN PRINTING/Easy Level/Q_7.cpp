/*
    1   2   3   4   5
    6   7   8   9   10
    11  12  13  14  15
    16  17  18  19  20
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row , col;
  cout << "Enter no. of rows and columns : ";
  cin >> row >> col;

  int cnt = 1;  
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
        cout << cnt << " ";
        cnt++;
    }
    cout << "\n";
  }

  return 0;
}