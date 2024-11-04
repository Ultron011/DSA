#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[], int n, int key) {
    if (n == 0) {
        return false;
    }

    if (arr[0] == key) {
        return true;
    } else {
        return linearSearch(arr+1, n-1, key);
    }
}

int main () {

  int arr[] = {2, 4, 6, 9, 12, 16};
  int n = sizeof(arr)/sizeof(arr[0]);

  int key;
  cout << "Enter the target element: ";
  cin >> key;

  if (linearSearch(arr, n, key)) {
    cout << key << " is present in the array." << endl;
  } else {
    cout << key << " is absent." << endl;
  }

  return 0;
}