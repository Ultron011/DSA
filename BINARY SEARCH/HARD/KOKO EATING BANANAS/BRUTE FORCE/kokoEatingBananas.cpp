/**
 * Problem Statement - 
 * 
 * Koko loves to eat bananas. There are `n` piles of bananas, the i-th pile has `piles[i]` bananas. 
 * The guards have gone and will come back in `h` hours. Koko can decide her bananas-per-hour eating speed of `k`. 
 * Each hour, she chooses some pile of bananas and eats `k` bananas from that pile. If the pile has less than `k` bananas, 
 * she eats all of them instead, and won't eat any more bananas during that hour.
 * 
 * Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards return.
 * 
 * Return the minimum integer `k` such that she can eat all the bananas within `h` hours.
 * 
 * Example - 
 * Input: piles = [3, 6, 7, 11], h = 8
 * Output: 4
 * Explanation: Koko can eat 4 bananas per hour. She will finish the piles in the following way:
 * - Hour 1: Eat 4 bananas from pile 1 (0 bananas left in pile 1)
 * - Hour 2: Eat 4 bananas from pile 2 (2 bananas left in pile 2)
 * - Hour 3: Eat 4 bananas from pile 3 (3 bananas left in pile 3)
 * - Hour 4: Eat 4 bananas from pile 4 (7 bananas left in pile 4)
 * - Hour 5: Eat 4 bananas from pile 4 (3 bananas left in pile 4)
 * - Hour 6: Eat 3 bananas from pile 1 (pile 1 is empty)
 * - Hour 7: Eat 2 bananas from pile 2 (pile 2 is empty)
 * - Hour 8: Eat 3 bananas from pile 3 (pile 3 is empty)
 * 
 * Input: piles = [30, 11, 23, 4, 20], h = 5
 * Output: 30
 * Explanation: Koko can eat 30 bananas per hour and finish all the piles within 5 hours.
 * 
 * Input: piles = [30, 11, 23, 4, 20], h = 6
 * Output: 23
 * Explanation: Koko can eat 23 bananas per hour and finish all the piles within 6 hours.
 */

#include<bits/stdc++.h>
using namespace std;

/* 
    Time complexity - 
        O(max(arr) * n)
    
    Space complexity - 
        O(1)

*/

int func(vector<int> &arr, int hourlyRate) {
    int totalHours = 0;
    for (int i = 0; i < arr.size(); i++) {
        totalHours += ceil((double)arr[i]/hourlyRate);
    }
    return totalHours;
}

int minimumRateToEatBananas(vector<int> &arr, int h) {
    int maxi = *max_element(arr.begin(), arr.end());
    
    for (int i = 1;i <= maxi; ++i) {
        int reqTime = func(arr, i);
        if (reqTime <= h) return i;
    }

    return -1;
}

int main() {

    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
  

  return 0;
}