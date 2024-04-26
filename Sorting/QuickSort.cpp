/*
  Quick sort algorithm - 
    Time Complexity - 
      Best case - O(nlog(n))
      Average case - O(nlog(n))
      Worst case - O(n^2)
    Space Complexity -
      O(log(n))
*/

#include<bits/stdc++.h>
using namespace std;

void displayArray(int *arr, int size) {
  for (int i = 0; i < size ; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

/* Partition taking first element as pivot */
int partition(int *arr, int s, int e) {
  int pivot = arr[s];
  int i = s - 1;
  for (int j = s ; j <= e; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i], arr[s]);
  return i;
}

void quickSort(int *arr, int s, int e) {
  if ( s < e) {
    int pivotIndex = partition(arr, s, e);

    quickSort(arr, s, pivotIndex - 1);

    quickSort(arr, pivotIndex +1, e);
  }
}



int main () {

  int arr[] = {15, 13, 45, 19, 16};
  int size = sizeof(arr)/sizeof(arr[0]);

  quickSort(arr, 0, size - 1);

  displayArray(arr, size);

  return 0;
}