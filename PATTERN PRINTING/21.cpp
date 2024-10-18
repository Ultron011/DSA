/*
            1
          2 1
        3 2 1
      4 3 2 1
    5 4 3 2 1
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
    for (int j = i+1; j >= 1; j--) {
        cout << j << " ";
    }
    cout << "\n";
  }

  return 0;
}