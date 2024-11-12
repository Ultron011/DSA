/*
  Time complexity - 
      O(n)
  Space complexity -
      O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> arr, int n) {
    int sumOfNaturalNumbers = (n * (n + 1)) / 2;

    int sumOfArrayElements = 0;
    for (int i : arr) {
        sumOfArrayElements += i;
    }

    return sumOfNaturalNumbers - sumOfArrayElements;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n-1);
  for (int i = 0; i < n-1; i++) {
    cin >> arr[i];
  }

  cout << "The missing Number is : " << missingNumber(arr, n) << endl;

  return 0;
}