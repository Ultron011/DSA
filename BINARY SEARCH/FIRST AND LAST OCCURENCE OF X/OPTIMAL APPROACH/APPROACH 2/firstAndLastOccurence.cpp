/*
  Problem Statement - 
    Given a sorted array of N integers, write a program to find the 
    index of the first and the last occurrence of the target key. If the target is 
    not found then return -1.

    Note: Consider 0 based indexing

    Input: N = 7, target=13, array[] = {3,4,13,13,13,20,40}
    Output: 2, 4
    Explanation: As the target value is 13 , it appears for the first time at index number 2 and 
                 last time at index number 4.
    
*/

#include<bits/stdc++.h>
using namespace std;

/*
  Time Complexity - O(log(n))
  Space Complexity - O(1)
*/

int firstOccurence(vector<int> &arr, int x) {
  int n = arr.size();

  int low = 0, high = n - 1;
  int first = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == x) {
      first = mid;
      high = mid - 1;
    } else if (arr[mid] > x) high = mid - 1;
    else low = mid + 1;
  }

  return first;
}

int lastOccurence(vector<int> &arr, int x) {
  int n = arr.size();

  int low = 0, high = n - 1;
  int last = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == x){
      last = mid;
      low = mid + 1;
    }
    else if (arr[mid] > x) high = mid - 1;
    else low = mid + 1;
  }

  return last;
}

pair<int, int> firstAndLastOccurence(vector<int> &arr, int x) {
    int n= arr.size();

    int first = firstOccurence(arr, x);
    int last = lastOccurence(arr, x);
    
    return {first, last};
    
}

int main() {

  vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
  cout << "Enter x : ";
  int x;
  cin >> x;
  pair<int, int> res = firstAndLastOccurence(arr, x);
  
  cout << res.first << " " << res.second << endl;

  return 0;
}