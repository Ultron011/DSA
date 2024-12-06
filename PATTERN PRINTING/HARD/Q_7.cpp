/*
    1 2 3 4 5 5 4 3 2 1
    1 2 3 4 * * 4 3 2 1
    1 2 3 * * * * 3 2 1
    1 2 * * * * * * 2 1
    1 * * * * * * * * 1
*/


#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  cout << "Enter the number of rows: ";
  cin >> row;

  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= row - i + 1; j++) {
        cout << j << " ";
    }
    for (int k = 1; k <= 2*(i-1); k++) {
        cout << "* ";
    }
    for (int j = row - i + 1; j >= 1; j--) {
        cout << j << " ";
    }
    cout << "\n";
  }
  return 0;
}