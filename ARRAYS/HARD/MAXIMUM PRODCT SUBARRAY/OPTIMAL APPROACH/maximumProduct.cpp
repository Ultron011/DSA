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
        O(n)

    Space Complexity -
        O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int maximumProduct(vector<int> &arr) {
    int n = arr.size();
    int maxProd = INT_MIN;
    int prefixProd = 1, suffixProd = 1;
    for (int i = 0; i < n; i++) {
        if (prefixProd == 0) prefixProd = 1;
        if (suffixProd == 0) suffixProd = 1;

        prefixProd = prefixProd * arr[i];
        suffixProd = suffixProd * arr[n - i - 1];
        maxProd = max(maxProd, max(prefixProd, suffixProd));
    }
    return maxProd;
}

int main() {

  vector<int> arr {2, 3, -2, 4};

  int ans = maximumProduct(arr);
  cout << "Maximum Subarray Prodct is : " << ans << endl;

  return 0;
}