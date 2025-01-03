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
        O(nlogn + klogn),  n = size of the given array, k = no. of gas stations to be placed.    
    
    Space complexity - 
        O(n-1)
*/

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); //size of array.
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;
    for (int i = 0; i < n - 1; ++i) {
        pq.push({arr[i+1] - arr[i], i});
    }

    for (int gasStations = 1; gasStations <= k; gasStations++) {
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double iniDiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = iniDiff / (long double) (howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }

    return pq.top().first;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
