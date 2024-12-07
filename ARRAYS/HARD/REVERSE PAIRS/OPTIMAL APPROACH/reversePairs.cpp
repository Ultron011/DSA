/*
    Problem Statement: Reverse Pairs
        Given an integer array nums, your task is to find the number of reverse pairs in the array. 
        A reverse pair is defined as a pair of indices (i, j) such that:
            0 ≤ i < j < nums.length, and
            nums[i] > 2 * nums[j].
        
        Input - 
            nums = [2, 4, 3, 5, 1]
        Output - 
            3

        Explanation:
            The reverse pairs are:
            (0, 4) → nums[0] = 2 and nums[4] = 1,
            (1, 4) → nums[1] = 4 and nums[4] = 1, and
            (2, 4) → nums[2] = 3 and nums[4] = 1.
*/

/*
    Time Complexity-
        O(n*log(n))
        
    Space Complexity - 
        O(n + log(n))
*/

#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int mid, int e) {
    vector<int> temp;
    int left = s;
    int right = mid + 1;

    // Merge two sorted halves
    while (left <= mid && right <= e) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= e) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy back to the original array
    for (int i = s; i <= e; i++) {
        arr[i] = temp[i - s];
    }
}

int countPairs(vector<int> &arr, int s, int mid, int e) {
    int cnt = 0;
    int right = mid + 1;

    for (int i = s; i <= mid; i++) {
        while (right <= e && arr[i] > 2LL * arr[right]) {
            right++;
        }
        cnt += (right - (mid + 1));
    }

    return cnt;
}

int mergeSort(vector<int> &arr, int s, int e) {
    if (s >= e) {
        return 0;
    }

    int mid = s + (e - s) / 2;
    int cnt = 0;

    // Count reverse pairs in left and right halves, and across the split
    cnt += mergeSort(arr, s, mid);
    cnt += mergeSort(arr, mid + 1, e);
    cnt += countPairs(arr, s, mid, e);

    // Merge the two halves
    merge(arr, s, mid, e);

    return cnt;
}

int main() {

  vector<int> arr = {40, 25, 19, 12, 9, 6, 2};

  int res = mergeSort(arr, 0, arr.size() - 1);
  
  cout << "The number of reverse pairs is : " << res << endl;

  return 0;
}