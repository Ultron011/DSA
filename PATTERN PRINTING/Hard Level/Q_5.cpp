/*
    *             *
    * *         * *
    * * *     * * *
    * * * * * * * *
    * * *     * * *
    * *         * *
    *             *
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  cout << "Enter no. of rows : ";
  cin >> row;

  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= i; j++) {
        cout << "* ";
    }
    for (int k = 0; k < 2 * (row - i); k++) {
        cout << "  ";
    }
    for (int j = 1; j <= i; j++) {
        cout << "* ";
    }
    cout << "\n";
  }

  for (int i = row-1; i >= 1; i--) {
    for (int j = 1; j <= i; j++) {
        cout << "* ";
    }
    for (int k = 0; k < 2 * (row - i); k++) {
        cout << "  ";
    }
    for (int j = 1; j <= i; j++) {
        cout << "* ";
    }
    cout << "\n";
  }

  return 0;
}