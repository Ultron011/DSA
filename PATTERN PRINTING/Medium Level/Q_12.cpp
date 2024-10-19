/*
            A
          A B
        A B C
      A B C D
    A B C D E
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
        char c = 'A' + j;
        cout << c << " ";
    }
    cout << "\n";
  }

  return 0;
}