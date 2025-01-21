#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O (N * M)

    Space complexity - O (N * M)
*/

class Solution {

    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image,int newColor,int iniColor) {
        if (row < 0 || row >= image.size() || col < 0 || col >= image[0].size() || image[row][col] != iniColor || ans[row][col] == newColor) return;

        ans[row][col] = newColor;
        dfs(row + 1, col, ans, image, newColor, iniColor);
        dfs(row - 1, col, ans, image, newColor, iniColor);
        dfs(row, col + 1, ans, image, newColor, iniColor);
        dfs(row, col - 1, ans, image, newColor, iniColor);
    }

    public:
        vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
            int iniColor = image[sr][sc];
            vector<vector<int>> ans = image;

            dfs(sr, sc, ans, image, newColor, iniColor);

            return ans;
        }
};

int main(){
		
	vector<vector<int>>image{
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};
	
// sr = 1, sc = 1, newColor = 2  	
	Solution obj;
	vector<vector<int>> ans = obj.floodFill(image, 1, 1, 2);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}
	
	return 0;
}