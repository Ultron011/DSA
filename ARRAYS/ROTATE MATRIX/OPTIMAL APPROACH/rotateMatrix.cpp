/*
    Problem Statement: Rotate Matrix
    You are given an 𝑁×𝑁 where N is the number of rows and columns. 
    Write a function to rotate the matrix 90 degrees clockwise in place, i.e., 
    without using any additional matrix or significant extra space.

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
        O(n/2*n/2)

    Space compleixty -
        O(1)

*/

#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &matrix) {
    int n = matrix.size();    
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i+1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
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

  vector<vector<int>> matrix  = {{1, 2, 3,4}, 
                                 {5, 6, 7, 8}, 
                                 {9, 10, 11, 12}, 
                                 {13, 14, 15,16}};

  rotateMatrix(matrix);
  
  printmatrixay(matrix);

  return 0;
}