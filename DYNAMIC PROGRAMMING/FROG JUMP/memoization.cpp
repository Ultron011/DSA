#include<bits/stdc++.h>
using namespace std;

int solve(int index, vector<int> &memo, vector<int>& height) {
    if (index == 0) return 0;

    if (memo[index] != -1) return memo[index];

    int jumpOne = solve(index-1, memo, height) + abs(height[index] - height[index-1]);
    int jumpTwo = INT_MAX;
    if (index > 1) {
        jumpTwo = solve(index-2, memo, height) + abs(height[index] - height[index-2]);
    }
    
    memo[index] = min(jumpOne, jumpTwo);
    return memo[index];
}

/*
    Time complexity - O(n)
    Space complexity - O(n)
*/
int frogJump(vector<int> &height) {
    int n = height.size();
    vector<int> memo(n, -1);
    return solve(n-1, memo, height);
}

int main() {
    vector<int> height = {30, 20, 50, 10, 40};
    cout << "Minimum cost to reach top: " << frogJump(height) << endl;
    return 0;
}