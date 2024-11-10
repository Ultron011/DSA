#include<bits/stdc++.h>
using namespace std;

int secondSmallestElement(vector<int> &arr) {
    if (arr.size() < 2) {
        throw invalid_argument("Array must contain at least two elements.");
    }

    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }
    }

    if (secondSmallest == INT_MAX) {
        throw invalid_argument("There is no second smallest element.");
    }

    return secondSmallest;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Second Smallest element is : " << secondSmallestElement(arr) << endl;

  return 0;
}