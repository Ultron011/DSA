/*
    Time Complexity:
        Best Case: O(n log(n))
        Average Case: O(n log(n))
        Worst Case: O(n^2)

    Space Complexity: 
        Best Case Space Complexity: O(log(n))
        Average Case Space Complexity: O(log n))
         Worst Case Space Complexity: O(n)
*/

#include<bits/stdc++.h>
using namespace std;


int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int i = s;
    int j = e;
    while (i < j) {
        while (arr[i] <= pivot && i < e) {
            i++;
        }
        while (arr[j] > pivot && j > s) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[s], arr[j]);
    return j;
}

void quickSort(int arr[], int s, int e) {
    if (s < e) {
        int p = partition(arr, s , e);

        quickSort(arr, s, p- 1);
        quickSort(arr, p+1, e);

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

  quickSort(arr, 0, size-1);

  printArray(arr, size);

  return 0;
}