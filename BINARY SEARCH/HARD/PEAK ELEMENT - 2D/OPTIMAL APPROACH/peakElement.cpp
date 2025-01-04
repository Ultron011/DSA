/**
 * Problem: Peak Element in a 2D Array
 * 
 * Problem Statement:
 * Given a 2D array of integers, find a peak element. A peak element is an element that is greater than or equal to its four possible neighbors (left, right, top, bottom). For the elements on the border of the array, we need to consider only the valid neighbors.
 * 
 * Sample Input:
 * [
 *   [10, 20, 15],
 *   [21, 30, 14],
 *   [7, 16, 32]
 * ]
 * 
 * Sample Output:
 * 30
 * 
 * Explanation:
 * In the given 2D array, the element 30 is a peak element because it is greater than or equal to its neighbors (21, 20, 14, and 16). Note that there can be multiple peak elements in a 2D array, and any one of them can be returned.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(n * log(m))

    Space complexity -
        O(1)

*/

int findMaxIndex(vector<vector<int>> &mat, int n, int m, int col) {
    int maxValue = INT_MIN;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (mat[i][col] > maxValue) {
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> peakElement(vector<vector<int>> &matrix, int n, int m) {
    int low = 0, high = m - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int maxRowIndex = findMaxIndex(matrix, n, m, mid);
        int left = mid  - 1 >= 0 ? matrix[maxRowIndex][mid-1] : -1;
        int right = mid + 1 < m ? matrix[maxRowIndex][mid+1] : -1;
        if (matrix[maxRowIndex][mid] > left && matrix[maxRowIndex][mid] > right) {
            return {maxRowIndex, mid};
        } else if (matrix[maxRowIndex][mid] < left) high = mid  - 1;
        else low = mid + 1;
    }

    return {-1, -1};
}

int main() {

  vector<vector<int>> matrix = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
  int n = matrix.size();
  int m = matrix[0].size();
  vector<int> ans = peakElement(matrix, n, m);
  cout << "Peak element is at index : { " ;
  for (auto it : ans) {
    cout << it << " ";
  }
  cout << "}";

  return 0;
}