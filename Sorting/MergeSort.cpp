/*
  Merge sort algoithm -
    Time complexity -
      Best case - O(nlog(n))
      Average case - O(nlog(n))
      Worst case - O(nlog(n))
    space complexity - O(n)
*/


#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int mid, int e) {
  int n1 = mid - s + 1;
  int n2 = e - mid;

  int *L = new int[n1];
  int *R = new int[n2];

  for (int i = 0; i < n1; i++) {
    L[i] = arr[s + i];
  }

  for (int j = 0; j < n2; j++) {
    R[j] = arr[mid + 1 + j];
  }

  int index1 = 0, index2 = 0;
  int mainArrayIndex = s;
  while (index1 < n1 && index2 < n2) {
    if (L[index1] <= R[index2]) {
      arr[mainArrayIndex++] = L[index1++];
    }
    else {
      arr[mainArrayIndex++] = R[index2++];
    }
  }

  while (index1 < n1) {
    arr[mainArrayIndex++] = L[index1++];
  }
  while (index2 < n2) {
    arr[mainArrayIndex++] = R[index2++];
  }

  delete []L;
  delete []R;
}

void mergeSort(int *arr, int s, int e) {
  if (s < e) {
    int mid = s + (e -s)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge(arr, s, mid , e);
  }
}

int main () {

  int arr[] = {1, 52, 3, 25, 551, 12, 55, 12, 22, 12};
  int size = sizeof(arr)/sizeof(arr[0]);

  mergeSort(arr, 0, size-1);

  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}