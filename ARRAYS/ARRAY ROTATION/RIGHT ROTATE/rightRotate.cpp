/*
    Right Rotate an array by D places.

    Input - 
        5 - (size of array)
        [1, 2, 3, 4, 5] - (Array)
        2 - (No. of times to rotate)
    Output - 
        [4, 5, 1, 2, 3]
*/

/*
    Time complexity - O(n^2)
*/


#include<bits/stdc++.h>
using namespace std;

void rightRotate(vector<int> &arr, int d) {
    int n = arr.size();
    d = d % n;

    while (d--) {
        int last = arr[n - 1];
        for (int i = n - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
            }
            arr[0] = last;
    }
}

void printArray(vector<int> arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}


int main () {

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int d;
    cin >> d;

    cout << "Original Array - " ;
    printArray(arr);
    rightRotate(arr, d);
    cout << "Right Rotated Array - ";
    printArray(arr);

  return 0;
}