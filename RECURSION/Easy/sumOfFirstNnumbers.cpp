#include<bits/stdc++.h>
using namespace std;

int sumOfNaturalNumbers(int n){
    if (n == 0) {
        return 0;
    }
    
    return n + sumOfNaturalNumbers(n-1);
}

int main () {

  int n;
  cout << "Enter the number n : ";
  cin >> n;

  int sum = sumOfNaturalNumbers(n);
  cout << "Sum of first " << n << " natural numbers is : " << sum << endl;


  return 0;
}