/*
    Problem Statement - 
        Given a sorted array of integers and a target element, use binary search 
        algorithm to print the index of the target element . In case the target 
        element is not present in the array , print element not found.

    Input - 
        [3, 4, 6, 7, 9, 12, 16]
        6 --> target
    
    Output - 
        2 --> Index of target element 6
*/

#include<bits/stdc++.h>
using namespace std;

/* 
    Time Complexity - O(log(n))

    Space Complexity - O(1)

*/

int binarySearch(vector<int> &nums, int target) {
    int n = nums.size();

    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) high = mid - 1;
        else low = mid + 1;
    }

    return -1;

} 

int main() {

  vector<int> nums = {3, 4, 6, 7, 9, 12, 16, 17};
  cout << "Enter the target element : ";
  int target;
  cin >> target;

  int targetIndex = binarySearch(nums, target);

  if (targetIndex != -1) {
    cout << target << " is found at index : " << targetIndex << "\n";
  } else {
    cout << target << " is not found in the array." << "\n";
  }

  return 0;
}