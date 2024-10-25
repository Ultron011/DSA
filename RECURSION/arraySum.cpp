#include<bits/stdc++.h>
using namespace std;

int arraySum(int arr[], int n) {
    if (n == 1) {
        return arr[0];
    }
    if (n == 0) {
        return 0;
    }

    int sum = arr[0] + arraySum(arr+1, n-1);
    return sum;

}

int main () {

  int arr[] = {2, 4, 6, 9, 12, 16};
  int n = sizeof(arr)/sizeof(arr[0]);

  int sum = arraySum(arr, n);
  cout << sum << endl;

  return 0;
}