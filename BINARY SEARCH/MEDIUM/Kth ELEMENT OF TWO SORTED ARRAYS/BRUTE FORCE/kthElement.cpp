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
    Time complexity -  O(m+n), where m and n are the sizes of the given arrays.

    Space complexity -  O(m+n), where m and n are the sizes of the given arrays.
*/

            
int kthElement(vector<int> &a, vector<int>& b,int k) {
    vector<int> arr3;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) arr3.push_back(a[i++]);
        else arr3.push_back(b[j++]);
    }

    //copy the left-out elements:
    while (i < a.size()) arr3.push_back(a[i++]);
    while (j < b.size()) arr3.push_back(b[j++]);
    return arr3[k - 1];
}

int main()
{
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    cout << "The k-ht element of two sorted array is: " << kthElement(a, b, 5) << '\n';
}