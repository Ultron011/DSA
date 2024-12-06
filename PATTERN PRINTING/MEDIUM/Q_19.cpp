/*
    1 2 3 4
      2 3 4
        3 4
          4
*/


#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  cout << "Enter the number of rows: ";
  cin >> row;

  for (int i = 1; i <= row; i++) {
    for (int k = 1; k <= i -1; k++) {
        cout << "  ";
    }
    for (int j = i; j <= row; j++) {
        cout << j << " ";
    }
    cout << "\n";
  }

  return 0;
}