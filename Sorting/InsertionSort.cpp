/*
  Insertion Sort - 
    Time Complexity - 
      Best case - O(n)
      Average case - O(n^2)
      Worst case - O(n^2)
    Space Complexity - O(1)
*/

#include<bits/stdc++.h>
using namespace std;

void displayArray(int arr[], int size) {
  for (int i = 0; i< size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void insertionSort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    int temp = arr[i];
    int j = i-1;
    while (arr[j] > temp && j >= 0) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = temp;
  }
}

int main () {

  int arr[] = {15, 13, 45, 19, 16};
  int size = sizeof(arr)/sizeof(arr[0]);

  insertionSort(arr, size);

  displayArray(arr, size);

  return 0;
}