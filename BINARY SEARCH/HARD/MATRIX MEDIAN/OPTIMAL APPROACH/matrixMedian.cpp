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
        O(log(10^9)) X O(M(logN)), where M = number of rows in the given matrix, N = number of columns in the given matrix

    Space complexity - 
        O(1)

*/

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    //point low and high to right elements:
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
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