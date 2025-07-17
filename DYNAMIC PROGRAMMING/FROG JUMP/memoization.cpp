#include<bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &memo, vector<int>& height) {
    if (n == 0) return 0;

    if (memo[n] != -1) return memo[n];

    int jumpOne = solve(n-1, memo, height) + abs(height[n] - height[n-1]);
    int jumpTwo = INT_MAX;
    if (n > 1) {
        jumpTwo = solve(n-2, memo, height) + abs(height[n] - height[n-2]);
    }
    
    memo[n] = min(jumpOne, jumpTwo);
    return memo[n];
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