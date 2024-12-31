/*
    Problem Statement:
        Given a rotated sorted array which may contain duplicates, 
        write a function to search for a target value. If the target is 
        found in the array, return its index. Otherwise, return -1.

        You may assume no duplicate exists in the original array before rotation.

    Input: nums = [2,5,6,0,0,1,2], target = 0
    Output: 3

    Explanation:
        The array [2,5,6,0,0,1,2] is a rotated version of the sorted array [0,0,1,2,2,5,6].
        The target value 0 is found at index 3 in the rotated array.
*/

#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity -   
        O(log(n))
    
    Space Complexity - 
        O(1)
*/

int searchInRotatedSorted(vector<int> &arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1;

    while (low <=  high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;

        // Identify the sorted half
        // check if left half is sorted or not ? 
        if (arr[mid] >= arr[low]) {
            // If left sorted, then check if target is in left part
            if (target >= arr[low] && target < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            // If right sorted, then check if target is in right part
            if (target > arr[mid] && target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {

  vector<int> arr = {7, 8, 9 , 1, 2, 3, 4, 5, 6};
  cout << "Enter the target: ";
  int target;
  cin >> target;

  int targetIndex = searchInRotatedSorted(arr, target);
  if (targetIndex != -1) {
    cout << target << " found at index : " << targetIndex << endl;
  } else {
    cout << target << " not found in the array." << endl;
  }

  return 0;
}

