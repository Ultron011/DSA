/**
 * Problem Statement :- Minimum Days to Make m Bouquets
 * 
 * Given an integer array bloomDay, an integer m and an integer k.
 * We need to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
 * The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
 * Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets, return -1.
 * 
 * Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
 * Output: 3
 * Explanation: Let's see what happened in the first three days. x means flower bloomed and _ means flower didn't bloom in the garden.
 * Day 1: [x, _, _, _, _]   // We can only make one bouquet.
 * Day 2: [x, _, _, _, x]   // We can only make two bouquets.
 * Day 3: [x, _, x, _, x]   // We can make 3 bouquets. So the answer is 3.
 * 
 * Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
 * Output: -1
 * Explanation: We need 3 bouquets each containing 2 adjacent flowers.
 * After day 3, the garden looks like [x, _, x, _, x]. It is impossible to make 3 bouquets.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity - 
        O((max(arr[])-min(arr[])+1) * N), where {max(arr[]) -> maximum element of the array, min(arr[]) -> minimum element of the array, N = size of the array}.
        
    Space Complexity - 
        O(1)
*/

bool possible(vector<int> &arr, int day, int m, int k) {
    int n = arr.size(); //size of the array
    int cnt = 0;
    int noOfB = 0;
    // count the number of bouquets:
    for (int i = 0; i < n; i++) {
        if (arr[i] <= day) {
            cnt++;
        }
        else {
            noOfB += (cnt / k);
            cnt = 0;
        }
    }
    noOfB += (cnt / k);
    return noOfB >= m;
}

int roseGarden(vector<int> &arr, int k, int m) {
    long long val = k * 1ll * m * 1ll;
    int n  = arr.size();
    if (val > n) return -1;


    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());

    for (int i = mini ; i <= maxi; ++i) {
        if (possible(arr, i, k, m)) {
            return i;
        }
    }

    return -1;
        
}

int main()
{
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}