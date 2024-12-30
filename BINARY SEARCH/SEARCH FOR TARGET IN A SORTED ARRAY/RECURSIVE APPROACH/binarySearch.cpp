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

    Space Complexity - O(log(n))

*/

int binarySearch(vector<int> &nums,int low, int high, int target) {
    if (low > high) return -1;

    int mid = low + (high - low)/2;

    if (nums[mid] == target) return mid;
    else if (nums[mid] > target) binarySearch(nums, low, mid - 1, target);
    else binarySearch(nums, mid + 1, high, target);

} 

int main() {

  vector<int> nums = {3, 4, 6, 7, 9, 12, 16, 17};
  cout << "Enter the target element : ";
  int target;
  cin >> target;

  int targetIndex = binarySearch(nums,0, nums.size() - 1, target);

  if (targetIndex != -1) {
    cout << target << " is found at index : " << targetIndex << "\n";
  } else {
    cout << target << " is not found in the array." << "\n";
  }

  return 0;
}