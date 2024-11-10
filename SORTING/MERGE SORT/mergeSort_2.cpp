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
    vector<int> temp;
    int leftArrayIndex = s;
    int rightArrayIndex = mid  + 1;
    while (leftArrayIndex <= mid && rightArrayIndex <= e) {
        if (arr[leftArrayIndex] < arr[rightArrayIndex]) {
            temp.push_back(arr[leftArrayIndex++]);
        } else{
            temp.push_back(arr[rightArrayIndex++]);
        }
    }

    while (leftArrayIndex <= mid) {
        temp.push_back(arr[leftArrayIndex++]);
    } 
    while (rightArrayIndex <= e) {
        temp.push_back(arr[rightArrayIndex++]);
    }


    for (int i = s; i < e; i++) {
        arr[i] = temp[i - s];
    }

    
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