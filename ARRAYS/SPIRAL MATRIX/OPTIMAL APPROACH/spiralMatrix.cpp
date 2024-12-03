/*
    Problem Statement: Spiral Matrix
        Given an M×N matrix, write a function to return all the elements of the matrix in spiral order, 
        starting from the top-left corner and moving inward in a clockwise direction.

    Input - 
        matrix = [[1, 2, 3],
                  [4, 5, 6],
                  [7, 8, 9]]
    
    Output -
        [1, 2, 3, 6, 9, 8, 7, 4, 5]


*/

/*
    Time complexity - 
        O(n*m)

    Space compleixty -
        O(n*m)

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;
    vector<int> ans;

    while (top <= bottom && left <= right) {
        // right 
        for (int i = left; i <= right; i++) {
            ans.push_back(matrix[top][i]);
        }
        top++;

        // bottom
        for (int i = top; i <= bottom; i++) {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom) {
            //left
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right) {
            // top
            for (int i = bottom; i>= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;

}


void printmatrixay(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

  vector<vector<int>> matrix  = {{1, 2, 3,4}, 
                                 {5, 6, 7, 8}, 
                                 {9, 10, 11, 12}, 
                                 {13, 14, 15,16}};

  printmatrixay(matrix);
  vector<int> ans = spiralMatrix(matrix);
  cout << "Spiral Matrix : " ;
  for (int i : ans) {
    cout << i << " ";
  }

  return 0;
}