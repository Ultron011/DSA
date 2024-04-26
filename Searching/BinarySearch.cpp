/* 
  Binary Search algorithm - 
    Time complexity - O(log(n))
    Space complexity - O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[],  int size, int target) {
  int s = 0 , e = size - 1;
  while ( s <= e) {
    int mid = s + (e-s)/2;
    if (arr[mid] == target) {
      return mid;
    }
    else if (arr[mid] > target) {
      e = mid - 1;
    }
    else {
      s = mid + 1;
    }
  }
  return -1;
}

int main () {

  int arr[] = {1, 5, 10, 12, 16, 20};
  int size = sizeof(arr)/sizeof(arr[0]);

  int target;
  cout << "Enter the target element: ";
  cin >> target;

  int index = binarySearch(arr, size, target);
  if (index != -1) {
    cout << target << " found at index " << index << " in the array." << endl;
  }
  else{
    cout << target << " not found in the array." << endl;
  }

  return 0;
}