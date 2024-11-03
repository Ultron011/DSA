#include<bits/stdc++.h>
using namespace std;

void arrayReverse(int arr[], int s , int e) {
    if (s > e) {
        return ;
    }

    swap(arr[s], arr[e]);
    arrayReverse(arr, s + 1, e - 1);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n ;i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {

  int arr[] = {1, 4, 2, 51, 6, 46};
  int size = sizeof(arr)/sizeof(arr[0]);

  arrayReverse(arr, 0, size-1);

  printArray(arr, size);

  return 0;
}