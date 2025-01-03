/**
 * Problem: Minimize Max Distance to Gas Stations
 * 
 * Problem Statement:
 * Given an array of integers representing the positions of gas stations along a highway, 
 * and an integer K representing the number of additional gas stations to be added, 
 * determine the minimum possible value of the maximum distance between adjacent gas stations 
 * after adding the K additional gas stations.
 * 
 * The goal is to minimize the maximum distance between any two adjacent gas stations.
 * 
 * Sample Input:
 * positions = [1, 2, 3, 4, 5, 6, 7, 8, 9]
 * K = 3
 * 
 * Sample Output:
 * 1.0
 * 
 * Explanation:
 * By adding 3 additional gas stations optimally, the maximum distance between any two adjacent gas stations 
 * can be minimized to 1.0. For example, adding gas stations at positions 1.5, 2.5, and 3.5 would result in 
 * the following distances between adjacent gas stations: [0.5, 0.5, 0.5, 0.5, 1, 1, 1, 1, 1], 
 * where the maximum distance is 1.0.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(n*log(Len)) + O(n), n = size of the given array, Len = length of the answer space.    
    
    Space complexity - 
        O(n-1)
*/

int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int n = arr.size(); // size of the array
    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); // size of the array
    long double low = 0;
    long double high = 0;

    //Find the maximum distance:
    for (int i = 0; i < n - 1; i++) {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    //Apply Binary search:
    long double diff = 1e-6 ;
    while (high - low > diff) {
        long double mid = (low + high) / (2.0);
        int cnt = numberOfGasStationsRequired(mid, arr);
        if (cnt > k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return high;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
