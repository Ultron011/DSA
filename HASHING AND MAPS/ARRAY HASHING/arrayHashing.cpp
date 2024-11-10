/*
  Maximum size array - 
    In local scope - 10^6
    In Global scope - 10^7
*/



#include<bits/stdc++.h>
using namespace std;

int main () {

  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int hash[50] = {0};
  for (int i = 0; i < n; i++) {
    hash[arr[i]]++;
  }


  int q;
  cin >> q;
  while(q--) {
    int number;
    cin >> number;

    cout << hash[number] << endl;
  }

  return 0;
}