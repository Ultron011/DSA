/**
 * Problem - Median of Two Sorted Arrays
 *
 * Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
 *
 * Input: nums1 = [1, 3], nums2 = [2]
 * Output: 2.0
 * Explanation: The merged array is [1, 2, 3] and the median is 2.
 *
 * Input: nums1 = [1, 2], nums2 = [3, 4]
 * Output: 2.5
 * Explanation: The merged array is [1, 2, 3, 4] and the median is (2 + 3) / 2 = 2.5.
 *
 */

#include<bits/stdc++.h>
using namespace std;

/*

    Time complexity - O(n1+n2), where  n1 and n2 are the sizes of the given arrays.

    Space complexity - O(n1+n2), where  n1 and n2 are the sizes of the given arrays.

*/

double median(vector<int> &a, vector<int> &b) {
    int n1 = a.size();
    int n2 = b.size();

    vector<int> c;
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            c.push_back(a[i++]);
        } else {
            c.push_back(b[j++]);
        }
    }

    while (i < n1) c.push_back(a[i++]);
    while (j < n2) c.push_back(b[j++]);

    int n = n1 + n2;
    if (n & 1) {
        // odd
        double median = ((double)c[n / 2] + (double)c[(n / 2) - 1]) / 2.0;
        return median; 
    } 
    else {
        // even
        return (double)c[n/2];
    }
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median(a, b) << '\n';
}