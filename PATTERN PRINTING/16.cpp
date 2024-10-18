/*
    5
    5 4
    5 4 3
    5 4 3 2
    5 4 3 2 1
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  cout << "Enter no. of rows : ";
  cin >> row;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j <= i; j++) {
        cout << row - j << " ";
    }
    cout << "\n";
  }

  return 0;
}