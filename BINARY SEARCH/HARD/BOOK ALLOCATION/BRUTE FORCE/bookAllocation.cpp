/**
 * Problem: Book Allocation
 * 
 * Problem Statement:
 * You are given an array of integers where each integer represents the number of pages in a book. 
 * There are 'm' students and the task is to allocate books to these students such that:
 * 1. Each student gets at least one book.
 * 2. Each book should be allocated to exactly one student.
 * 3. The maximum number of pages assigned to a student is minimized.
 * 
 * You need to find the minimum possible value of the maximum number of pages assigned to a student.
 * 
 * Sample Input:
 * books = [12, 34, 67, 90]
 * m = 2
 * 
 * Sample Output:
 * 113
 * 
 * Explanation:
 * There are 4 books with page counts [12, 34, 67, 90] and 2 students.
 * The optimal way to allocate books is:
 * - Student 1: [12, 34, 67] => Total pages = 113
 * - Student 2: [90] => Total pages = 90
 * The maximum number of pages assigned to a student is 113, which is the minimum possible in this case.
 */

#include<bits/stdc++.h>
using namespace std;

/*
    Time Complexity- 
        O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.

    Space Complexity-
        O(1)

*/

int cntStudents(vector<int> &arr, int pages) {
    int n = arr.size();
    int std = 1;
    int page = 0;
    for (int i = 0; i < n ; ++i) {
        if (page + arr[i] <= pages) {
            page += arr[i];
        } else {
            std++;
            page = arr[i];
        }
    }
    return std;
}

int findPages(vector<int> &arr, int n, int m) {
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    for (int pages = low ; pages <= high; pages++) {
        int noOfStudents = cntStudents(arr, pages);
        if (noOfStudents == m) return pages;
    }
    return -1;
}

int main()
{
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";
    return 0;
}