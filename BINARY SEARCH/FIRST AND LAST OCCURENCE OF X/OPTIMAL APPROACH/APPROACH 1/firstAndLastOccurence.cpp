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

pair<int, int> firstAndLastOccurence(vector<int> &arr, int x) {
    int n= arr.size();

    int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int ub = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

    if (lb == n || arr[lb] != x) return {-1, -1};
    
    return {lb, ub - 1};
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