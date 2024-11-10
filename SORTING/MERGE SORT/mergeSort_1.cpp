/*

    Time Complexity:
        Best Case: O(n log(n))
        Average Case: O(n log(n))
        Worst Case: O(n log(n))

    Space Complexity: O(n)

*/

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int s, int mid, int e) {
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

    int leftArrayIndex = 0, rightArrayIndex = 0;
    int mainArrayIndex = s;

    while (leftArrayIndex < n1 && rightArrayIndex < n2) {
        if (L[leftArrayIndex] < R[rightArrayIndex]) {
            arr[mainArrayIndex++] = L[leftArrayIndex++];
        } else {
            arr[mainArrayIndex++] = R[rightArrayIndex++];
        }
    }

    while (leftArrayIndex < n1) {
        arr[mainArrayIndex++] = L[leftArrayIndex++];
    }
    while (rightArrayIndex < n2) {
        arr[mainArrayIndex++] = R[rightArrayIndex++];
    }

    delete[] L;
    delete[] R;
    
}

void mergeSort(int arr[], int s, int e) {
    if ( s < e) {
        int mid = s + (e -s)/2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {

  int arr[] = {5, 45, 16, 8, 95, 12, 46, 2, 53, 62, 15};
  int size = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, size);

  mergeSort(arr, 0, size - 1);

  printArray(arr, size);



  return 0;
}