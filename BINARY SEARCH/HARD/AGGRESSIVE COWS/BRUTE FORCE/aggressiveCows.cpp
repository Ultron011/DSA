/**
 * Problem: Aggressive Cows
 * 
 * Problem Statement:
 * You are given an array of integers representing the positions of stalls on a number line. 
 * You need to place a given number of cows in these stalls such that the minimum distance 
 * between any two cows is as large as possible. Your task is to determine this largest minimum distance.
 * 
 * Sample Input:
 * stalls = [1, 2, 4, 8, 9]
 * cows = 3
 * 
 * Sample Output:
 * 3
 * 
 * Explanation:
 * The stalls are located at positions [1, 2, 4, 8, 9]. We need to place 3 cows in these stalls.
 * One way to place the cows is at positions 1, 4, and 8. The minimum distance between any two cows 
 * in this arrangement is 3 (between stalls 1 and 4, and between stalls 4 and 8). 
 * There is no way to place the cows such that the minimum distance is larger than 3.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity -
        O(NlogN) + O(N *(max(stalls[])-min(stalls[]))), where N = size of the array, max(stalls[]) = maximum element in stalls[] array, min(stalls[]) = minimum element in stalls[] array.

    Space Complexity -
        O(1)
*/

bool canWePlace(vector<int> &stalls, int dist, int cows) {
    int n = stalls.size();
    int cntCows = 1;
    int last = stalls[0];
    for (int i = 0; i < n; i++) {
        if (stalls[i] - last >= dist) {
            cntCows++;
            last = stalls[i];
        }
        if (cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int limit = stalls[n-1] - stalls[0];
    for (int i = 1; i < limit; i++) {
        if (canWePlace(stalls, i, k) == false) {
            return i - 1;
        }
    }
    return limit;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}