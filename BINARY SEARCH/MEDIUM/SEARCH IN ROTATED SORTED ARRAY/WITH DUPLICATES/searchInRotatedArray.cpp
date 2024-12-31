/*
    Problem Statement:
        Given a rotated sorted array which may contain duplicates, 
        write a function to search for a target value. If the target is 
        found in the array, return its index. Otherwise, return -1.

        You may assume duplicate exists in the original array before rotation.

    Input: nums = [3, 1, 2, 3, 3, 3, 3], target = 1
    Output: true

    Explanation:
        The array [3, 1, 2, 3, 3, 3, 3] is a rotated version of the sorted array [1, 2, 3, 3, 3, 3, 3].
        The target value 1 is found in the rotated array.
*/

#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity -   
        For average case - O(log(n))
        For Worst case (when all elements are identical) - O(n)
    
    Space Complexity - 
        O(1)
*/

bool searchInRotatedSorted(vector<int> &arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return true;

        if (arr[mid] == arr[low] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        if (arr[mid] >= arr[low]) {
            if (target >= arr[low] && target < arr[mid]) high = mid - 1;
            else low = mid + 1;
        } else {
            if (target > arr[mid] && target <= arr[high]) low = mid + 1;
            else high = mid - 1;
        }
    }

    return false;
    
}

int main() {

  vector<int> arr = {3, 1, 2, 3, 3, 3, 3};
  cout << "Enter the target: ";
  int target;
  cin >> target;

  int targetIndex = searchInRotatedSorted(arr, target);
  if (targetIndex) {
    cout << target << " found in the array." << endl;
  } else {
    cout << target << " not found in the array." << endl;
  }

  return 0;
}

