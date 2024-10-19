/*
          1
        1 2 1
      1 2 3 2 1
    1 2 3 4 3 2 1
  1 2 3 4 5 4 3 2 1
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
        cout << j+1 << " ";
    }
    for (int l = i; l >= 1; l--) {
        cout << l << " ";
    }
    cout << "\n";
  }

  return 0;
}