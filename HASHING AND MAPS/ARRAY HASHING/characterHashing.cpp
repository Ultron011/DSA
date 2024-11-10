#include<bits/stdc++.h>
using namespace std;

int main () {

  string s;
  cin >> s;


  int charHash[26] = {0};
  for (int i = 0; i < s.length(); i++) {
    int index = s[i] - 'a';
    charHash[index]++;
  }


  int q;
  cin >> q;
  while(q--) {
    char c;
    cin >> c;
    cout << charHash[c - 'a'] << endl;
  }


  return 0;
}