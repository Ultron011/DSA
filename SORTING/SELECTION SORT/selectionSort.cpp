/*

    Time Complexity - O(n^2) ( Best, Average , Worst)
    Space Complexity - O(1)

*/

#include<bits/stdc++.h>
using namespace std;


void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for  (int j = i; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {

  int arr[] = {2, 10, 5, 16, 8};
  int size = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, size);

  selectionSort(arr, size);

  printArray(arr, size);

  return 0;
}