/*
    Input -   
        [0, 0, 2, 3, 1, 4, 0]
    
    Output - 
        [2, 3, 1, 4, 0, 0, 0]

*/


/*
    Time complexity - 
        O(2n)
    
    Space complexity - 
        O(n)

*/


#include<bits/stdc++.h>
using namespace std;

void movingZeroes(vector<int>& arr) {
    int n = arr.size();

    vector<int> temp;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp.push_back(arr[i]);
        }
    }

    int i = 0;
    while ( i < temp.size()) {
        arr[i] = temp[i];
        i++;
    }

    while (i < arr.size()) {
        arr[i] = 0;
        i++;
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