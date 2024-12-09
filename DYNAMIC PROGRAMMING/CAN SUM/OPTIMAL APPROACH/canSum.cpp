/*
  Time complexity - 
    O(m * n), where m is the target sum and n is the size of the array.

  Space complexity - 
    O(m), where m is the target sum (due to recursion and memoization storage).
*/

#include <bits/stdc++.h>
using namespace std;

bool canSum(int targetSum, vector<int> numbers, unordered_map<int, bool>& memo) {
    if (targetSum == 0) return true;  // Base case: If we reach 0, a combination exists
    if (targetSum < 0) return false; // If we overshoot, no combination exists

    // Check if the result is already memoized
    if (memo.find(targetSum) != memo.end()) {
        return memo[targetSum];
    }

    // Try each number in the array
    for (int num : numbers) {
        int remainder = targetSum - num;
        if (canSum(remainder, numbers, memo)) {
            memo[targetSum] = true; // Memoize result for current targetSum
            return true;
        }
    }

    memo[targetSum] = false; // Memoize result for current targetSum
    return false;
}

int main() {

  /*
    8, {2, 3, 5}
    7, {2, 4}
    7, {5, 3, 4, 7}
    7, {2, 3}
    300, {7, 14}
  
  */

    int n, targetSum;
    cout << "Enter the number of elements and targetSum: ";
    cin >> n >> targetSum;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
      cin >> numbers[i];
    }

    unordered_map<int, bool> memo;
    cout << canSum(targetSum,numbers, memo) << endl;

    return 0;
}
