/*
    Sample Input -
        [2, 4, 6, 7, 11]
        
    Sample Output - 
        Array is sorted
*/

#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n) {
    if (n == 0 || n == 1) {
        return true;
    }

    if (arr[0] > arr[1]) {
        return false;
    } else {
        return isSorted(arr + 1, n - 1);
    }

}

int main () {

  int arr[] = {2, 4, 6, 9, 12, 16};
  int n = sizeof(arr)/sizeof(arr[0]);

  if (isSorted(arr, n)) {
    cout << "Array is sorted";
  }  else {
    cout << "Array is not sorted";
  }

  return 0;
}