/*
          *
        * * *
      * * * * *
    * * * * * * *
  * * * * * * * * *
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  cout << "Enter no. of rows : ";
  cin >> row;

  for (int i = 0; i < row; i++) {
    for (int k = 0; k < row - i - 1; k++) {
        cout << "  ";
    }
    for (int j = 0; j <= i; j++) {
        cout << "* ";
    }
    for (int l = 0; l < i; l++) {
        cout << "* ";
    }
    cout << "\n";
  }

  return 0;
}