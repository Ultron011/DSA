/*
    Problem Statement: 
        Given an integer array arr of size N, sorted in ascending order (with distinct values). 
        Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 

    Sample Input - 
        arr = [4,5,6,7,0,1,2,3]

    Sample Output - 
        4
    
    Explanation:
        Here, the array is rotated 4 times.

*/

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(log(n))
    Space complexity - O(1)
*/

int numberOfRotations(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int mini = INT_MAX;
    int index = -1;


    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[low] <= arr[high]) {
            // array is already sorted
            if (arr[low] < mini) {
                index = low;
                mini = arr[low];
            }
            break;
        }

        if (arr[mid] >= arr[low]) {
            if (arr[low] < mini) {
                index = low;
                mini = arr[low];
            }
            low = mid + 1;
        } else {
            if (arr[mid] < mini) {
                index = mid;
                mini = arr[mid];
            }
            high = mid - 1;
        }
    }

    return index;
}

int main() {

  vector<int> arr = {4, 5, 6, 0, 1, 2, 3};

  int rotations = numberOfRotations(arr);
  cout << "Array is Rotated : " << rotations << endl;

  return 0;
}