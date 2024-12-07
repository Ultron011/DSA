/*
    Problem Statement: Maximum Product Subarray
        You are given an array of integers nums containing both positive and negative numbers. 
        Your task is to find the contiguous subarray (containing at least one number) within the array that has the largest product, 
        and return this maximum product.

        Input - 
            nums = [2, 3, -2, 4]

        Output - 
            6

        Explanation - 
            The subarray [2, 3] has the largest product: 2×3=6.

*/

/*
    Time Complexity- 
        O(n^2)

    Space Complexity -
        O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> &arr) {
    int n = arr.size();
    int maxProduct = INT_MIN;

    for (int i = 0; i < n; i++) {
        int prod = 1;
        for (int j = i; j < n; j++) {
            prod *= arr[j];
            maxProduct = max(maxProduct, prod);
        }
    }
    return maxProduct;
}

int main() {

  vector<int> arr {2, 3, -2, 4};

  int ans = maximumProduct(arr);
  cout << "Maximum Subarray Prodct is : " << ans << endl;

  return 0;
}