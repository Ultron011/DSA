/*
    1 1 1 1 
      2 2 2 
        3 3 
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
    for (int j = 1; j <= row - i + 1; j++) {
        cout << i << " ";
    }
    cout << "\n";
  }

  return 0;
}