/*
    Problem Statement: 
        You're given an sorted array arr of n integers and an integer x. 
        Find the floor and ceiling of x in arr[0..n-1].
        The floor of x is the largest element in the array which is smaller than or equal to x.
        The ceiling of x is the smallest element in the array greater than or equal to x.

    Sample Input -  
        n = 6, arr[] ={3, 4, 4, 7, 8, 10}, x= 5

    Sample Output - 
        4 7

    Explantion - 
        The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.
*/

#include<bits/stdc++.h>
using namespace std;

int floorOfX(vector<int> arr, int x) {
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] <= x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    } 

    // If high is -1, there is no floor element (x is smaller than the smallest element).
    if (high >= 0) {
        return arr[high];
    } else {
        return -1;  // or any other error value to indicate no floor exists.
    }
}

int ceilOfX(vector<int> arr, int x) {
    int n = arr.size(); 
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    // If low is out of bounds, there is no ceil element (x is larger than the largest element).
    if (low < n) {
        return arr[low];
    } else {
        return -1;  // or any other error value to indicate no ceil exists.
    }
}

int main() {

  vector<int> arr = {3, 4, 4, 7, 8, 10};
  cout << "Enter x : ";
  int x;
  cin >> x;
  int floor = floorOfX(arr, x);
  int ceil = ceilOfX(arr, x);

  cout << "Floor : " << floor << "\n";
  cout << "Ceil : " << ceil << "\n";

  return 0;
}