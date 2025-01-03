/**
 * Problem - Kth Missing Positive Integer
 * 
 * Description -  
 * Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
 * Return the kth positive integer that is missing from this array.
 * 
 * Input: arr = [2, 3, 4, 7, 11], k = 5
 * Output: 9
 * Explanation: The missing positive integers are [1, 5, 6, 8, 9, 10, 12, ...]. The 5th missing positive integer is 9.
 * 
 * Input: arr = [1, 2, 3, 4], k = 2
 * Output: 6
 * Explanation: The missing positive integers are [5, 6, 7, ...]. The 2nd missing positive integer is 6.
 * 
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(log(n))

    Space complexity -
        O(1)

*/

int missingK(vector<int> &vec, int n, int k) {
    int low = 0, high = n - 1;
    while (low <=  high) {
        int mid = low + (high - low) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k) low = mid + 1;
        else high = mid - 1;
    }

    return low + k;
}

int main()
{
    vector<int> vec = {4, 7, 9, 10};
    int n = 4, k = 4;
    int ans = missingK(vec, n, k);
    cout << "The missing number is: " << ans << "\n";
    return 0;
}