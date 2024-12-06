/*
    1
    2 3
    3 4 5
    4 5 6 7
*/


#include<bits/stdc++.h>
using namespace std;

int main () {

  int row;
  cout << "Enter the no. of rows: ";
  cin >> row;

  for (int i = 1; i <= row; i++) {
    for (int j = 1; j <= i; j++)  {
        cout << i + j - 1 << " ";
    }
    cout << "\n";
  }


  return 0;
}