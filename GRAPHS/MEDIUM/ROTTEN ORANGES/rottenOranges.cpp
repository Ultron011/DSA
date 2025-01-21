#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O (N * M)

    Space complexity - O (N * M)
*/

int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> vis = grid;
    int cntFresh = 0;
    queue<pair<int, int>> q;

    for (int i= 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j] == 2) {
                q.push({i, j});
            }
            if (vis[i][j] == 1) cntFresh++;
        }
    }

    if (cntFresh == 0) return 0;
    if (q.empty()) return -1;

    int min = -1;
    int delrow[] = {-1, 0, 1, 0};
    int delcol[] = {0, 1, 0, -1};

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int r = q.front().first;
            int c = q.front().second;

            q.pop();
            for (int i = 0; i < 4; i++) {
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 2;
                    cntFresh--;
                    q.push({nrow, ncol});
                }
            }
        }
        min++;
    }

    if (cntFresh != 0) return -1;
    return min;
}

int main()
{
    vector<vector<int>> v{ {2,1,1} , {1,1,0} , {0,1,1} } ;
    int rotting = orangesRotting(v);
    cout<<"Minimum Number of Minutes Required "<<rotting<<endl;
        
}