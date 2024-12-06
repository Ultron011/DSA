/*
    Problem Statement: Rotate Matrix
    You are given an 𝑁×𝑁 where N is the number of rows and columns. 
    Write a function to rotate the matrix 90 degrees clockwise in place.

    Input - 
        matrix = [[1, 2, 3],
                  [4, 5, 6],
                  [7, 8, 9]]
    
    Output -
        matrix = [[7, 4, 1],
                  [8, 5, 2],
                  [9, 6, 3]]


*/

/*
    Time complexity - 
        O(n^2)

    Space compleixty -
        O(n^2)

*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();

    vector<vector<int>> ans(n, vector<int>(n));
    
    for (int i  =0; i< n; i++) {
        for (int j = 0;j < n; j++) {
            ans[j][n-i - 1] = matrix[i][j];
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

  vector<vector<int>> ans = rotateMatrix(matrix);
  
  printmatrixay(ans);

  return 0;
}