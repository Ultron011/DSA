#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(N * M)

    Space complexity - O(N * M)
*/

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>> vis(n, vector<int> (m, 0));
       queue<pair<int, int>> q;

       for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
       }
       
       int delrow[] = {-1, 0, 1, 0};
       int delcol[] = {0, 1, 0, -1};

       while (!q.empty()) {
        int r = q.front().first;
        int c= q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if (nrow >= 0 && ncol < n && ncol >= 0 && ncol < n && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;
            }
        }
       }

       int cnt = 0;
       for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && !vis[i][j]) {
                cnt++;
            }
        }
       }

       return cnt;

    }
};

int main() {
    
    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
        
    Solution obj;
    cout << obj.numberOfEnclaves(grid) << endl;

}