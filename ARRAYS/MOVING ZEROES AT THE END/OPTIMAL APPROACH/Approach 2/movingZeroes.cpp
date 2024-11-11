/*
    Input -   
        [0, 0, 2, 3, 1, 4, 0]
    
    Output - 
        [2, 3, 1, 4, 0, 0, 0]

*/



/*
    Time complexity - O(n)

*/

#include<bits/stdc++.h>
using namespace std;

void movingZeroes(vector<int>& arr) {
    int nonZeroIndex = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != 0) {
            arr[nonZeroIndex] = arr[i];
            nonZeroIndex++;
        }
    }

    for (int i = nonZeroIndex; i < arr.size(); i++) {
        arr[i] = 0;
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
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

    printArray(arr);

    movingZeroes(arr);

    printArray(arr);


  return 0;
}