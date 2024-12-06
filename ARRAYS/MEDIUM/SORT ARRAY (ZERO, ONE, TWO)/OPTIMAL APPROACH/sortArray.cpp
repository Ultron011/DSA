/*
    Input - 
        [0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1]
    Output - 
        [0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2]
*/

/*
    Dutch National Flag Algorithm

    Time complexity - 
        O(n)
    Space complexity 0 
        O(1)
*/

#include<bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &arr) {
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
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