/* 
    Left Rotate an array by D places.

    Input - 
        5 - (size of array)
        [1, 2, 3, 4, 5] - (Array)
        2 - (No. of times to rotate)
    Output - 
        [3, 4, 5, 1, 2]
*/

/*
    Time complexity - 
        O(n + d)
    Space Complexity - 
        O(d)
*/


#include<bits/stdc++.h>
using namespace std;

void leftRotate(vector<int> &arr, int d) {

    d = d % arr.size();

    /* Creating a temporary vector to store elments upto d places */
    vector<int> temp;
    for (int i = 0; i < d; i++) {
        temp.push_back(arr[i]);
    }

    /* Shifting elements */
    for (int i = d; i < arr.size(); i++) {
        arr[i-d] = arr[i];
    }

    /* Inserting the stored elements at the end of original vector/array */
    for (int i = 0; i < d; i++) {
        arr[arr.size() - d + i] = temp[i];
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
    leftRotate(arr, d);
    cout << "Right Rotated Array - ";
    printArray(arr);

  return 0;
}