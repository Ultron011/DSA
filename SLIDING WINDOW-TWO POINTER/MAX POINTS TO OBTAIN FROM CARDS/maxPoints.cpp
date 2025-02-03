/**
 * The problem is to find the maximum score you can obtain by picking exactly k cards from a given array of integers.
 * You can pick cards from either the beginning or the end of the array.
 *
 * Example:
 * --------
 * Input:
 * arr = {6, 2, 3, 4, 7, 2, 1, 7, 1}
 * k = 4
 *
 * Output:
 * Max Points that can be obtained : 18
 *
 * Explanation:
 * You can pick the first 3 cards (6, 2, 3) and the last card (7) to get a total score of 6 + 2 + 3 + 7 = 18.
 */
#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(2 * K);

    Space complexity - O(1)
*/

int maxScore(vector<int> arr, int k) {
    int lsum = 0, rsum = 0, maxSum = 0;
    for (int i = 0; i < k; i++) lsum = lsum + arr[i];
    maxSum = lsum;

    int rindex = arr.size() - 1;
    for (int i = k-1; i >= 0 ; i--) {
        lsum = lsum - arr[i];
        rsum += arr[rindex];
        rindex--;

        maxSum = max(maxSum, lsum+rsum);
    }

    return maxSum;

}

int main() {

  vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
  int k = 4;

  int ans = maxScore(arr, k);
  cout << "Max Points that can be obtained : " << ans << endl;

  return 0;
}