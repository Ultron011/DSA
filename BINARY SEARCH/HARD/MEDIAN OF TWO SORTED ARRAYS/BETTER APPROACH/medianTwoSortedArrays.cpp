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

    Space complexity - O(1)

*/

double median(vector<int> &a, vector<int> &b) {
    int n1 = a.size();
    int n2 = b.size();

    int n = n1 + n2;
    int ind1 = n / 2;
    int ind2 = ind1 - 1;

    int ind1el = INT_MIN, ind2el = INT_MIN;
    int cnt = 0;

    int i= 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        } else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }

    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }


    if (n & 1) {
        // odd
        double median = double(ind1el + ind2el) / 2.0;
        return median; 
    } 
    else {
        // even
        return (double)ind1el;
    }

}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median(a, b) << '\n';
}