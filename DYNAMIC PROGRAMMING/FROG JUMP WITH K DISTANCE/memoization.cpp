#include<bits/stdc++.h>
using namespace std;



/*
    Time complexity - O(n)
    Space complexity - O(n)
*/
int frogJumpWithKDistances(int k , vector<int> &height) {
    int n = height.size();
    vector<int> memo(n, -1);
    
    
}

int main() {
    vector<int> height = {10, 30, 40, 50, 20};
    int k = 3;
    cout << "Minimum cost to reach top: " << frogJumpWithKDistances(k, height) << endl;
    return 0;
}