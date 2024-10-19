/*
       *
      * *
     * * *
    * * * *
    * * * *
     * * *
      * *
       *
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  cout << "Enter no. of rows : ";
  cin >> row;

  for (int i = 1; i <= row; i++) {
    for (int k = 1; k <= row - i; k++) {
        cout << " ";
    }
    for (int j = 1; j <= i; j++) {
        cout << "* ";
    }
    cout << "\n";
  }

  for (int i = row; i >= 1; i--) {
    for (int k = 1; k <= row - i; k++) {
        cout << " ";
    }
    for (int j = 1; j <= i; j++) {
        cout << "* ";
    }
    cout << "\n";
  }
  

  return 0;
}