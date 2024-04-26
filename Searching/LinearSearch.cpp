/*
  Linear search algorithm - 
    Time Complexity - O(n)
    Space Complexity - O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int size, int target) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      return i;
    }
  }
  return -1;
}


int main () {

  int arr[] = {15, 13, 45, 19, 16};
  int size = sizeof(arr)/sizeof(arr[0]);

  int target;
  cout << "Enter the target element: ";
  cin >> target;

  int index = linearSearch(arr, size, target);
  if (index != -1) {
    cout << target << " found at index " << index << " in the array." << endl;
  }
  else{
    cout << target << " not found in the array." << endl;
  }

  return 0;
}