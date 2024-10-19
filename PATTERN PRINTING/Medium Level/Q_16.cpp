/*
    D
    C D
    B C D
    A B C D
*/


#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  cout << "Enter the number of rows: ";
  cin >> row;

  for (int i = 1; i <= row; i++) {
    char c = 'A' + row - i;
    for (int j = 1; j <= i; j++) {
        cout << c << " ";
        c++;
    }
    cout << "\n";
  }

  return 0;
}