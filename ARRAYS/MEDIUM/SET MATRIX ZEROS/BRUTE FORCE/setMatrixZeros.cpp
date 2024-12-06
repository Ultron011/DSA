/*
    Time complexity - 
        O(n^3)
    
    Space complexity - 
        O(1)

*/

#include<bits/stdc++.h>
using namespace std;

void markRowCol(vector<vector<int>> &matrix, int i, int j) {
    int row = matrix.size();
    int col  = matrix[0].size();

    for (int k = 0; k < col; k++) {
        if (matrix[i][k] != 0) {
            matrix[i][k] = -1;
        }
    }

    for (int k = 0; k < row; k++) {
        if (matrix[k][j] != 0) {
            matrix[k][j] = -1;
        }
    }
}

void setMatrixZeros(vector<vector<int>>&matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRowCol(matrix, i , j);
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m ; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }
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

  vector<vector<int>> matrix  = {{1, 1, 1,1}, 
                                 {1, 0, 1, 1}, 
                                 {1, 1, 0, 1}, 
                                 {1, 0, 0,1}};

  setMatrixZeros(matrix);

  printmatrixay(matrix);

  return 0;
}