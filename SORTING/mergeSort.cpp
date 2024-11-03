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

    int i = 0, j = 0;
    int k = s;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }

    delete []L;
    delete []R;
}

void mergeSort(int arr[] , int s, int e) {
    if (s < e) {
        int mid = s + (e - s) / 2;
        mergeSort(arr, 0, mid);
        mergeSort(arr, mid+1, e);
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