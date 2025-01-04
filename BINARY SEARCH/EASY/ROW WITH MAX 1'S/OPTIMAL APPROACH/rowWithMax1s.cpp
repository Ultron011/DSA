/**
 * Problem - Row with maximum number of 1's
 * 
 * Description - Given a binary matrix (a matrix consisting of only 0s and 1s), 
 *              find the row with the maximum number of 1's. The matrix is sorted 
 *              in non-decreasing order, meaning that all the 0s will be before any 1s in a row.
 * 
 * Input -
 * matrix = [
 *   [0, 0, 0, 1],
 *   [0, 1, 1, 1],
 *   [1, 1, 1, 1],
 *   [0, 0, 0, 0]
 * ]
 * 
 * Output -
 * 2
 * 
 * Explanation - In the given matrix, the third row (index 2) has the maximum number of 1's (4 ones).
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(n X log(m)), where n = given row number, m = given column number.

    Space complexity - O(1)
*/

int noOf1s(vector<int> &arr, int m) {
    int low = 0, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] >= 1) high = mid - 1;
        else low = mid + 1;
    }

    return low;
}

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
    int cnt_max = 0;
    int index = -1;
    for (int i = 0; i < n; ++i) {
        int cnt_ones = m - noOf1s(matrix[i], m);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }

    return index;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " <<
         rowWithMax1s(matrix, n, m) << '\n';
}