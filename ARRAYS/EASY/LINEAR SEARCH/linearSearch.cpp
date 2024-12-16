#include<bits/stdc++.h>
using namespace std;

/*
  Time complexity - O(n)
  Space Complexity - O(1)
*/

int linearSearch(vector<int> arr, int key) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int key;
  cin >> key;

  int keyIndex = linearSearch(arr, key);
  if (keyIndex != -1) {
    cout << "Element is present at index " << keyIndex << endl; 
  } else {
    cout << "Element is not present in array" << endl;
  }



  return 0;
}