/*
    Problem Statement: 
        Given an array of N integers. Every number in the array except one appears twice. 
        Find the single number in the array.

    Input Format:
        arr[] = {1,1,2,2,3,3,4,5,5,6,6}

    Result:
        4

    Explanation:
        Only the number 4 appears once in the array.

*/

/*
    Time complexity - 
        O(log(n))
        
    Space complexity - 
        O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &arr) {
    int n = arr.size();

    if (n == 1) return arr[0];

    if (arr[0] != arr[1]) return arr[0];
    if (arr[n-1] != arr[n-2]) return arr[n-1];

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] != arr[mid+1] && arr[mid] != arr[mid - 1]) return arr[mid];

        /* Identical element is at left half (even, odd) */
        if (mid % 2 == 1 && arr[mid-1] == arr[mid] || mid % 2 == 0 && arr[mid] == arr[mid+1]) {
            low = mid + 1;
        } else {
            /* Identical element is at left half (odd, even) */
            high = mid - 1;
        }
    }

    return -1;
}

int main() {

  vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
  int ans = singleElement(arr);

  cout << "Single Element is : " << ans << endl;

  return 0;
}