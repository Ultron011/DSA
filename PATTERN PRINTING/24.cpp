/*
    * * * * * * * * *
      * * * * * * *
        * * * * *
          * * * 
            * 
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  cout << "Enter no. of rows : ";
  cin >> row;

  for (int i = 0; i < row; i++) {
    for (int k = 0; k < i; k++) {
        cout << "  ";
    }
    for (int j = 0; j < 2 * (row - i) - 1; j++) {
        cout << "* ";
    }
    cout << "\n";
  }

  return 0;
}