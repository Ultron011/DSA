/**
 * Problem - Searches for a target value in a 2D matrix.
 * 
 * The matrix has the following properties:
 * - Integers in each row are sorted in ascending order from left to right.
 * - Integers in each column are sorted in ascending order from top to bottom.
 * 
 * Input:
 * matrix = [
 *   [1, 4, 7, 11, 15],
 *   [2, 5, 8, 12, 19],
 *   [3, 6, 9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * target = 5
 * Output: true
 * 
 * Input:
 * matrix = [
 *   [1, 4, 7, 11, 15],
 *   [2, 5, 8, 12, 19],
 *   [3, 6, 9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * target = 20
 * Output: false
 * 
 * Explanation:
 * In the first example, the target value 5 is present in the matrix.
 * In the second example, the target value 20 is not present in the matrix.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(log(NxM)), where N = given row number, M = given column number.
        
    Space complexity -
        O(1)

*/

bool binarySearch(vector<int> &arr, int target) {
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] > target)  high = mid - 1;
        else low = mid + 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0, high = n*m - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int row = mid / m;
        int col = mid % m;
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) low = mid + 1;
        else high = mid - 1;
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}