/**
 * Problem Description:
 * --------------------
 * Given an array of integers, find a peak element. A peak element is an element that is greater than its neighbors.
 * For corner elements, we need to consider only one neighbor. The function should return the index of any one of the peak elements.
 *
 * Sample Input:
 * -------------
 * Input: arr[] = {1, 3, 20, 4, 6, 1, 0}
 *
 * Sample Output:
 * --------------
 * Output: 2 (or 4)
 *
 * Explanation:
 * ------------
 * The element at index 2 (value 20) is a peak element because it is greater than its neighbors (3 and 4).
 * The element at index 4 (value 6) is also a peak element because it is greater than its neighbors (4 and 1).
 * The function can return the index of any one of these peak elements.
 */

#include<bits/stdc++.h>
using namespace std;

int peakElement(vector<int> &arr) {
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] > arr[mid + 1]) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {

  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};

  int res = peakElement(arr);
  cout << "Peak element is at index : " << res << endl;

  return 0;
}
