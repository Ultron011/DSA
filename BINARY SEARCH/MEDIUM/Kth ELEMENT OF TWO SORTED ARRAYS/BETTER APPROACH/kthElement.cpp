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
    Time complexity - O(m+n), where m and n are the sizes of the given arrays.

    Space complexity - O(1)
*/

            
int kthElement(vector<int> &a, vector<int>& b, int m, int n, int k) {
    int ele = -1;
    int cnt = 0; //counter
    //apply the merge step:
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (a[i] < b[j]) {
            if (cnt == k - 1) ele = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == k - 1) ele = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < m) {
        if (cnt == k - 1) ele = a[i];
        cnt++;
        i++;
    }
    while (j < n) {
        if (cnt == k - 1) ele = b[j];
        cnt++;
        j++;
    }
    return ele;
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-ht element of two sorted array is: " << kthElement(a, b, a.size(), b.size(), 5) << '\n';
}