/*
    * * * * * * * *
    * * *     * * *
    * *         * *
    *             *
    *             *
    * *         * *
    * * *     * * *      
    * * * * * * * *
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  cout << "Enter no. of rows : ";
  cin >> row;

  for (int i = row; i > 0; i--) {
    for (int j = 0; j < i; j++) {
        cout << "* ";
    }
    for (int k = 0; k < 2 * (row - i); k++) {
        cout << "  ";
    }
    for (int j = 0; j < i; j++) {
        cout << "* ";
    }
    cout << "\n";
  }

  for (int i = 0; i < row ; i++) {
    for (int j = 0; j <= i; j++) {
        cout << "* ";
    }
    for (int k = 0; k < 2*(row - (i+1)); k++) {
        cout << "  ";
    }

    for (int j = 0; j <= i; j++) {
        cout << "* ";
    }
    cout << "\n";
  }


  return 0;
}