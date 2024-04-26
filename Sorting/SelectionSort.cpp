/*
  Selection sort algorithm - 
    Time Complexity -
      Best case - O(n^2)
      Average case - O(n^2)
      Worst case - O(n^2)
    Space Complexity - O(1)
*/

#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int size) {
  for (int i = 0; i < size - 1; i++) {
    int minIndex = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    swap(arr[minIndex], arr[i]);
  }
}

int main () {

  int arr[] = {15, 13, 45, 19, 16};
  int size = sizeof(arr)/sizeof(arr[0]);

  selectionSort(arr, size);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}