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
    long long n = arr.size();

    long long elementSum = 0;
    long long squareSum = 0;
    
    /* Find the sum of all array elements and square of all array elements */
    for (int i = 0; i < n; i++) {
        elementSum += arr[i];
        squareSum += (long long)(arr[i] * (long long)arr[i]);
    }

    /* Sum of first n natural numbers and square of all n natural numbers  */
    long long naturalSum = (n*(n+1)) / 2;
    long long sqaureNaturalSum = (n*(n+1)*(2*n + 1)) / 6;

    /* X - Y -- (i) */
    long long equationOne = elementSum - naturalSum;
    /* X + Y -- (ii) */
    long long equationTwo = (squareSum - sqaureNaturalSum);
    equationTwo /= equationOne;

    long long  repeating = (equationOne + equationTwo)/2;
    long long  missing = (equationTwo - repeating);
    

    cout << "Repeating Number : " << (int)repeating << "\n";
    cout << "Missing Number : " << (int)missing << "\n";
}

int main() {

  vector<int> arr = {4, 3, 6, 2, 1, 1};

  repeatingMissing(arr);

  return 0;
}