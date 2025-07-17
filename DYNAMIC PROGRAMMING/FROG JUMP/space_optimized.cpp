#include<bits/stdc++.h>
using namespace std;

int frogJump(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    if (n == 1) return 0;

    int prev2 = 0;                                 
    int prev1 = abs(height[1] - height[0]);         

    for (int i = 2; i < n; i++) {
        int curr = min(prev1 + abs(height[i] - height[i-1]),  prev2 + abs(height[i] - height[i-2]));
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    vector<int> height = {30, 20, 50, 10, 40};
    cout << "Minimum cost to reach top: " << frogJump(height) << endl;
    return 0;
}