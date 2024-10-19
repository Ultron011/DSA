/*
    A
    B C 
    D E F
    G H I J
*/


#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  cout << "Enter the number of rows: ";
  cin >> row;

  char c = 'A';
  for (int i = 0; i < row; i++) {
    for (int j = 0; j <= i; j++) {
        cout << c << " ";
        c++;
    }
    cout << "\n";
  }

  return 0;
}