#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(N^2)

    Space complexity - 
        O(N^2)

*/

class Solution {

    void bfs(vector<vector<char>> &grid, int i , int j, vector<vector<int>> &vis) {
        vis[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        int n = grid.size();
        int m = grid[0].size();
        int delrow[4] = {-1, 0, 1, 0 };
        int delcol[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r= q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];


                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

  public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;
        vector<vector<int>> vis(n, vector<int> (m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    bfs(grid, i , j, vis);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

int main() {
    
    vector<vector<char>> grid = {{'1', '1', '1', '1', '0'},
                                {'1', '1', '0', '1', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '0', '0', '0'}};
        
    Solution ob;
    cout << ob.numIslands(grid) << endl;
        
    return 0;
}