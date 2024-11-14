/*
    Input - 
        [0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1]
    Output - 
        [0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2]
*/

/*
    Time complexity - 
        O(2n)
    Space complexity 0 
        O(1)
*/

#include<bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr) {
    int cnt_zero = 0, cnt_one = 0, cnt_two = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) cnt_zero++;
        else if (arr[i] == 1) cnt_one++;
        else cnt_two++;
    }

    int i = 0;
    while (cnt_zero--) {
        arr[i++] = 0;
    }
    while (cnt_one--) {
        arr[i++] = 1;
    }
    while (cnt_two--) {
        arr[i++] = 2;
    }
}

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i =0; i < n; i++) {
    cin >> arr[i];
  }
  
  printArray(arr);
  sortArray(arr);
  printArray(arr);


  return 0;
}