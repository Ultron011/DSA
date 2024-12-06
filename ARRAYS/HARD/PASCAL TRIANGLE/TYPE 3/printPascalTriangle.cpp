/*
    Problem Statement: Pascal's Triangle
        Write a function that generates the first n rows of Pascal's Triangle.
    
    Pascal's Triangle - 
            1
           1, 1
          1, 2, 1
        1, 3, 3, 1
       1, 4, 6, 4, 1
        
        
    Input - 
        n = 5
    
    Output -
       [[1],
        [1, 1],
        [1, 2, 1],
        [1, 3, 3, 1],
        [1, 4, 6, 4, 1]]
    
+*/

/*
    Time complexity - 
        O(n*n*r) ~ O(n^3)
    
    Space complexity - 
        O(1)

*/

#include<bits/stdc++.h>
using namespace std;

int findElement(int r, int c) {
    long long ans = 1;
    for (int i = 0; i < c; i++) {
        ans = ans * (r - i);
        ans = ans / (i + 1);
    }
    return (int)(ans);
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    for (int row = 1; row <= n; row++) {
        vector<int> temp;
        for (int col = 1; col <= row; col++) {
            int ele = findElement(row -1, col - 1);
            temp.push_back(ele);
        }
        ans.push_back(temp);
    }
    return ans;

}

int main() {

  int n;
  cin >> n;

  vector<vector<int>> ans = pascalTriangle(n);
  for (auto it : ans) {
    for (auto ele : it) {
        cout << ele << " ";
    }
    cout << "\n";
  }

  return 0;
}