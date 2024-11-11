/*
    Input -   
        [0, 0, 2, 3, 1, 4, 0]
    
    Output - 
        [2, 3, 1, 4, 0, 0, 0]

*/


/*
    Time complexity - 
        O(n)
    
    Space complexity - 
        O(1)

*/


#include<bits/stdc++.h>
using namespace std;

void movingZeroes(vector<int>& arr) {
    int n = arr.size();

    int i = 0;
    while (i < n && arr[i] != 0) {
        i++;
    }

    int j = i + 1;
    while (j < n) {
        if (arr[j] != 0) {
            swap(arr[i], arr[j]);
            i++;
            j++;
        } else {
            j++;
        }
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