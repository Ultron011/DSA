/*
  Time complexity - 
    O(n^m) where n is no. of elements in the array and m is the height of the tree
  
  Space compleixty - 
    O(m) - m is the height of the tree

*/

#include<bits/stdc++.h>
using namespace std;

bool canSum(int targetSum, vector<int> numbers) {
    if (targetSum == 0) return true;
    if (targetSum < 0) return false;

    for (int num : numbers) {
        int remainder = targetSum - num;
        if (canSum(remainder, numbers)) {
            return  true;
        }
    }

    return false;
}

int main() {

  cout << canSum(7, {2, 3}) << endl;
  cout << canSum(7, {5, 3, 4, 7}) << endl;
  cout << canSum(7, {2, 4}) << endl;
  cout << canSum(8, {2, 3, 5}) << endl;

  return 0;
}