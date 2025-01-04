/**
 * Problem - Kth element of two sorted arrays
 * Description - Given two sorted arrays arr1 and arr2 of size n and m respectively, 
 *              find the k-th element in the merged sorted array.
 * 
 * Input: arr1 = [2, 3, 6, 7, 9], arr2 = [1, 4, 8, 10], n = 5, m = 4, k = 5
 * Output: 6
 * Explanation: The merged sorted array is [1, 2, 3, 4, 6, 7, 8, 9, 10]. The 5th element is 6.
 * 
 * Input: arr1 = [1, 3, 4, 8, 10], arr2 = [2, 5, 6, 7, 9], n = 5, m = 5, k = 7
 * Output: 6
 * Explanation: The merged sorted array is [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]. The 7th element is 6.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(log(min(m, n))), where m and n are the sizes of two given arrays.

    Space complexity - O(1)
*/

int kthElement(vector<int> &a, vector<int> &b, int k) {
    int n1 = a.size();
    int n2 = b.size();
    int n =  n1 + n2;
    if (n1 > n2) kthElement(b, a, k);

    int low = max(k-n2, 0), high = min(k, n1);
    int left = k;
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = a[mid1];
        if (mid2 < n2) r2 = b[mid2];
        if (mid1 - 1 >= 0) l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = b[mid2 - 1];
        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2);
        } else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }

    return 0;
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-ht element of two sorted array is: " << kthElement(a, b, 5) << '\n';
}