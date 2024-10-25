#include<bits/stdc++.h>
using namespace std;

void countingReverse(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countingReverse(n - 1);
}

void counting(int n) {
    if (n == 0) {
        return ;
    }
    counting(n-1);
    cout << n << " ";
}

int main () {

  int n;
  cout << "Enter the number: ";
  cin >> n;

  cout << "Counting : ";
  counting(n);

  cout << endl;

  cout << "Counting Reverse : ";
  countingReverse(n);

  return 0;
}