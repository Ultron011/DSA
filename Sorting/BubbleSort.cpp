/*
  Bubble sort algorithm - 
    Time Complexity - 
      Best case - O(n)
      Average case - O(n^2)
      Worst case - O(n^2)
    Space Complexity - O(1)
*/

#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    bool swapped = false;
    for (int j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j+1]);
        swapped = true;
      }
    }
    if (!swapped) {
      break;
    }
  }
}

int main () {

  int arr[] = {15, 13, 45, 19, 16};
  int size = sizeof(arr)/sizeof(arr[0]);

  bubbleSort(arr, size);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}