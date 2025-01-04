/**
 * Problem - Search in a row-wise and column-wise sorted matrix.
 *
 * Description - Given an n x m matrix where each row is sorted in ascending order from left to right,
 * and each column is sorted in ascending order from top to bottom, write a function that searches for a 
 * target value in the matrix. The function should return true if the target is found, and false otherwise.
 *
 * Input :
 * matrix = [
 *   [1, 4, 7, 11, 15],
 *   [2, 5, 8, 12, 19],
 *   [3, 6, 9, 16, 22],
 *   [10, 13, 14, 17, 24],
 *   [18, 21, 23, 26, 30]
 * ]
 * target = 5
 *
 * Output :
 * true
 *
 * Explanation The target value 5 is present in the matrix at position (1, 1).
 *
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(N + M), where N = given row number, M = given column number.
        
    Space complexity - 
        O(1)

*/



bool searchElement(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int row = 0, col = m - 1;
    while (row < n && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row++;
        else col--;
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    searchElement(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}

