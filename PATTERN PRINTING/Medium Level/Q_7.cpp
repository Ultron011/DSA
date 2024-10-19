/*
    1 2 3 4 5
    1 2 3 4
    1 2 3
    1 2 
    1
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  cout << "Enter no. of rows : ";
  cin >> row;

  for (int i = 0; i < row; i++) {
    for (int j = 1; j <= row - i; j++) {
        cout << j << " ";
    }
    cout << "\n";
  }

  return 0;
}