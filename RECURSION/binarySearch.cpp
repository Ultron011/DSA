#include<bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int s, int e, int key) {
    if (s > e) {
        return false;
    }
    
    int mid = s + (e-s)/2;
    if (arr[mid] == key) {
        return true;
    } 
    else if (arr[mid] > key) {
        return binarySearch(arr, s, mid-1, key);
    } else {
        return binarySearch(arr, mid+1, e, key);
    }
}

int main () {

  int arr[] = {2, 4, 6, 9, 12, 16};
  int n = sizeof(arr)/sizeof(arr[0]);

  int key;
  cout << "Enter the target element: ";
  cin >> key;

  if (binarySearch(arr, 0, n-1, key)) {
    cout << "Present";
  } else {
    cout << "Absent";
  }

  return 0;
}   