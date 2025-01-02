/**
 * Problem: Capacity to Ship Packages Within D Days
 *
 * Problem Statement:
 * You are given an array of weights representing the weights of packages, and an integer D 
 * representing the number of days within which all packages must be shipped. You need to find 
 * the minimum capacity of a ship that can ship all the packages within D days.
 * 
 * The ship can only carry packages in the given order, and it cannot split a package.
 * Each day, the ship can carry packages with a total weight up to its capacity. 
 * The goal is to minimize the ship's capacity while ensuring that all packages are shipped within D days.
 *
 * Sample Input:
 * weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
 * D = 5
 *
 * Sample Output:
 * 15
 *
 * Explanation:
 * A ship capacity of 15 is the minimum required to ship all packages within 5 days. The packages can be shipped as follows:
 * - Day 1: [1, 2, 3, 4, 5] (Total weight = 15)
 * - Day 2: [6, 7] (Total weight = 13)
 * - Day 3: [8] (Total weight = 8)
 * - Day 4: [9] (Total weight = 9)
 * - Day 5: [10] (Total weight = 10)
 * 
 * Any capacity less than 15 would require more than 5 days to ship all packages.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity - 
        O(N * (sum(weights[]) - max(weights[]) + 1)), where sum(weights[]) = summation of all the weights, max(weights[]) = maximum of all the weights, N = size of the weights array.        
    Space Complexity - 
        O(1)
*/

int daysReq(vector<int> &weights, int cap) {
  int days = 1, load = 0;
  for (int i = 0; i < weights.size(); i++) {
    if (load + weights[i] > cap) {
      days++;
      load = weights[i];
    } else {
      load += weights[i];
    }
  }
  return days;
}

int leastWeightCapacity(vector<int> &weights, int d) {
  int maxi = *max_element(weights.begin(), weights.end());
  int sum = accumulate(weights.begin(), weights.end(), 0);

  for (int i = maxi; i <= sum ; i++) {
    if (daysReq(weights, i) <= d) {
      return i;
    }
  }

  return -1;
  
}

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}