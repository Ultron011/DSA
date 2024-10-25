/*
    Sample Input -
        423

    Sample Output -
        FOUR TWO THREE

*/

#include<bits/stdc++.h>
using namespace std;

void sayDigits(int n) {
    string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR" , "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

    if (n == 0) {return;}

    int digit = n % 10;
    sayDigits(n/10);
    cout << digits[digit] << " ";
}

int main () {

  int n;
  cout << "Enter the number: ";
  cin >> n;

  sayDigits(n);

  return 0;
}