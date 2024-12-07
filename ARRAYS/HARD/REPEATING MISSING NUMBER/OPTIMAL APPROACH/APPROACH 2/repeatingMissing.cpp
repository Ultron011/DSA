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
        O(n)

    Space Complexity -
        O(1)
*/


#include<bits/stdc++.h>
using namespace std;

void repeatingMissing(vector<int> &arr) {
    int n = arr.size();
    int repeating = -1;
    int missing = -1;
    
    int xr = 0;
    for (int i = 0; i < n; i++) {
        xr ^= arr[i];
        xr ^= (i+1);
    }

    int bitNo = 0;
    while (1) {
        if ((xr & (1 << bitNo)) != 0) {
            break;
        }
        bitNo++;
    }

    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        /* Part of 1 club */
        if ((arr[i] & (1<<bitNo)) != 0) {
            one = one ^ arr[i];
        } else {
            /* Part of 0 club */
            zero = zero ^ arr[i];
        }
    }

    for (int i = 1; i<=n; i++) {
        if ((i & (1<<bitNo)) != 0) {
            one = one ^ i;
        } else {
            zero = zero ^ i;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == zero) cnt++;
    }
    if (cnt == 2) {
        repeating = zero;
        missing = one;
    } else {
        repeating = one;
        missing = zero;
    }


    cout << "Repeating Number : " << repeating << "\n";
    cout << "Missing Number : " << missing << "\n";
}

int main() {

  vector<int> arr = {4, 3, 6, 2, 1, 1};

  repeatingMissing(arr);

  return 0;
}