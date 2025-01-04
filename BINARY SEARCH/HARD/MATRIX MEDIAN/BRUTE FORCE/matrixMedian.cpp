/**
 * Problem : Median of Row Wise Sorted Matrix
 * 
 * Description :
 * Given a row-wise sorted matrix of size r x c, find the median of the matrix.
 * The matrix is sorted in non-decreasing order both row-wise and column-wise.
 * 
 * Input:
 * matrix = [
 *   [1, 3, 5],
 *   [2, 6, 9],
 *   [3, 6, 9]
 * ]
 * r = 3
 * c = 3
 * 
 * Output:
 * 5
 * 
 * Explanation
 * The sorted order of all elements in the matrix is [1, 2, 3, 3, 5, 6, 6, 9, 9].
 * The median is the middle element, which is 5.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(MXN) + O(MXN(log(MXN))), where M = number of row in the given matrix, N = number of columns in the given matrix

    Space complexity - 
        O(MXN) as we are using a temporary list to store the elements of the matrix.

*/

int median(vector<vector<int>> &mat, int m ,int n) {
    vector<int> arr;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr.push_back(mat[i][j]);
        }
    }

    sort(arr.begin(), arr.end());

    return arr[(n*m) / 2];
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(), n = matrix[0].size();
    int ans = median(matrix, m, n);
    cout << "The median element is: " << ans << endl;
    return 0;
}