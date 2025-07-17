#include<bits/stdc++.h>
using namespace std;

int frogJump(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    if (n == 1) return 0;

    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);

    for (int i = 2; i < n; ++i) {
        int jumpOne = dp[i - 1] + abs(height[i] - height[i - 1]);
        int jumpTwo = dp[i - 2] + abs(height[i] - height[i - 2]);
        dp[i] = min(jumpOne, jumpTwo);
    }

    return dp[n - 1];
}

int main() {
    vector<int> height = {30, 20, 50, 10, 40};
    cout << "Minimum cost to reach top: " << frogJump(height) << endl;
    return 0;
}