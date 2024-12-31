/*
    Problem Statement: 
        Given an integer array arr of size N, sorted in ascending order (with distinct values). 
        Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 

    Sample Input - 
        arr = [4,5,6,7,0,1,2,3]

    Sample Output - 
        0
    
    Explanation:
        Here, the element 0 is the minimum element in the array.

*/

#include<bits/stdc++.h>
using namespace std;

int mininumInRS(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int mini = INT_MAX;



    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[high]) {
            // array is already sorted
            mini = min(mini, arr[low]);
            break;
        }

        if (arr[mid] >= arr[low]) {
            mini = min(mini, arr[low]) ;
            low = mid + 1;
        } else {
            mini = min(mini , arr[mid]);
            high = mid - 1;
        }
    }

    return mini;
}

int main() {

  vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};

  int min= mininumInRS(arr);
  cout << "Minimum is : " << min << endl;

  return 0;
}