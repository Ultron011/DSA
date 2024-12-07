/*
    Problem Statement: Repeating and Missing Number
        You are given an array nums consisting of n integers, 
        where each integer is between 1 and n (inclusive). 
        The array contains exactly n elements, but one number is missing and another number is repeated. 
        Your task is to find the repeated number and the missing number.

    Input - 
        nums = [4, 3, 6, 2, 1, 1]

    Output - 
        (1, 5)

    Explanation:
        The repeated number is 1.
        The missing number is 5.
*/

/*
    Time Complexity - 
        O(n^2)

    Space Complexity -
        O(1)
*/


#include<bits/stdc++.h>
using namespace std;

void repeatingMissing(vector<int> &arr) {
    int n = arr.size();
    int repeating = -1;
    int missing = -1;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j] == i) {
                cnt++;
            }
        }
        if (cnt == 2) {
            repeating = i;
        } 
        else if (cnt == 0) {
            missing = i;
        }

        if (repeating != -1 && missing != -1) {
            break;
        }
    } 

    cout << "Repeating Number : " << repeating << "\n";
    cout << "Missing Number : " << missing << "\n";
}

int main() {

  vector<int> arr = {4, 3, 6, 2, 1, 1};

  repeatingMissing(arr);

  return 0;
}