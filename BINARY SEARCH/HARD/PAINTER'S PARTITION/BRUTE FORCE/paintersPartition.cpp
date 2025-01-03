/**
 * Problem: Painter's Partition Problem
 * 
 * Problem Statement:
 * Given an array of integers where each element represents the length of a board, 
 * and a number of painters available, the task is to find the minimum time required 
 * to paint all boards. Each painter can paint contiguous segments of boards, and 
 * each painter takes the same amount of time to paint one unit of board length.
 * 
 * The goal is to minimize the maximum amount of time taken by any painter.
 * 
 * Sample Input:
 * boards = [10, 20, 30, 40]
 * painters = 2
 * 
 * Sample Output:
 * 60
 * 
 * Explanation:
 * - One optimal way to partition the boards is [10, 20, 30] and [40].
 * - The first painter paints boards of length 10, 20, and 30, taking a total time of 60.
 * - The second painter paints the board of length 40, taking a total time of 40.
 * - The maximum time taken by any painter is 60, which is the minimum possible in this case.
 */


#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(N * (sum(arr[])-max(arr[])+1)), where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.

    Space complexity-
        O(1)

*/

int countPainters(vector<int> &boards, int time) {
    int n = boards.size(); //size of array.
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++) {
        if (boardsPainter + boards[i] <= time) {
            //allocate board to current painter
            boardsPainter += boards[i];
        }
        else {
            //allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);

    for (int time = low; time <= high; time++) {
        if (countPainters(boards, time) <= k) {
            return time;
        }
    }
    return low;
}

int main()
{
    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int ans = findLargestMinDistance(boards, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}
