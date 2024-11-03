#include<bits/stdc++.h>
using namespace std;

bool palindrome(string str, int s, int e) {
    if (s > e) {
        return true;
    }
    if (str[s] != str[e]) {
        return false;
    }
    return palindrome(str, s+1, e-1);

}

int main () {

  string str;
  cin >> str;

  if (palindrome(str, 0, str.length() - 1)) {
    cout << str << " is palindrome." << endl;
  } else {
    cout << str << " is not palindrome.";
  }

  return 0;
}