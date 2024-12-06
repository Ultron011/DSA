/*
    A B C D 
    B C D E
    C D E F
    D E F G
*/


#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  int col;
  cout << "Enter no. of rows and columns: ";
  cin >> row >> col;

  for (int i = 0; i < row; i++) {
    char c = 'A' + i;
    for (int j = 0; j < col; j++) {
        char ch = c + j;
        cout << ch << " ";
    }
    cout << "\n";
  }

  return 0;
}