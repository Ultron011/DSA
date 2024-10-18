/*
    a
    b b 
    c c c
    d d d d
    e e e e e
*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  cout << "Enter no. of rows : ";
  cin >> row;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j <= i; j++) {
        char c = 'a' + i;
        cout << c << " ";
    }
    cout << "\n";
  }

  return 0;
}