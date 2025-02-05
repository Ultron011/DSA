/**
 * Problem Statement:
 * You are visiting a farm that has a single row of fruit trees arranged from left to right. 
 * The trees are represented by an integer array `tree` where `tree[i]` is the type of fruit the ith tree produces.
 * You want to collect as much fruit as possible, but you can only use two baskets, and each basket can only hold one type of fruit.
 * You can start at any tree of your choice and move to any adjacent tree to the right, collecting one fruit from each tree.
 * The goal is to find the maximum number of fruits you can collect with the two baskets.
 * 
 * Sample Input:
 * tree = [1, 2, 1]
 * 
 * Sample Output:
 * 3
 * 
 * Explanation:
 * We can collect [1, 2, 1] which is a total of 3 fruits.
 * 
 * Sample Input:
 * tree = [0, 1, 2, 2]
 * 
 * Sample Output:
 * 3
 * 
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(N)

    Space complexity - O(N)
*/

int totalElements(vector<int> &arr) {
    int maxlen = 0;
    int n = arr.size();
    int l = 0, r= 0;
    unordered_map<int, int> freq;

    while (r < n) {
        freq[arr[r]]++;

        if (freq.size() > 2) {
            freq[arr[l]]--;
            if (freq[arr[l]] == 0) freq.erase(arr[l]);
            l++;
        }

        maxlen = max(maxlen, r - l + 1);
        r++;
    } 

    return maxlen;
    
}

int main() {

  vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4};
  int ans = totalElements(arr);
  cout << ans;

  return 0;
}