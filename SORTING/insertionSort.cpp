/*

    Time Complexity:
        Best Case: O(n)
        Average Case: O(n^2)
        Worst Case: O(n^2)

    Space Complexity:
        O(1)

*/

#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
} 


int main () {

    int arr[] = {2, 10, 5, 16, 8};
  int size = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, size);

  insertionSort(arr, size);

  printArray(arr, size);

  return 0;
}