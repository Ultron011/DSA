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
        O(N*logM), where N = given row number, M = given column number.
        
    Space complexity - 
        O(1)

*/

bool binarySearch(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    int low = 0, high = n - 1;

    // Perform the steps:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        else if (target > nums[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

bool searchElement(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        bool flag =  binarySearch(matrix[i], target);
        if (flag) return true;
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

