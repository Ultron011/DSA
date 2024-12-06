#include<bits/stdc++.h>
using namespace std;

int secondLargestElement(vector<int> &arr) {
    if (arr.size() < 2) {
        throw invalid_argument("Array must contain at least two elements.");
    }

    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    if (secondLargest == INT_MIN) {
        throw invalid_argument("There is no second largest element.");
    }

    return secondLargest;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Second Largest element is : " << secondLargestElement(arr) << endl;

  return 0;
}