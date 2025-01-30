#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(N) + O(V + 2E)

    Space complexity - 
        O(N)

*/

class Solution {

    void dfs(vector<vector<char>> &grid, int i , int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') return;

        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

  public:
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
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