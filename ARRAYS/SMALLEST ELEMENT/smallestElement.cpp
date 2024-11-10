#include<bits/stdc++.h>
using namespace std;

int smallestElement(vector<int> &arr) {
    
    int smallest = INT_MAX;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }

    return smallest;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Smallest element is : " << smallestElement(arr) << endl;

  return 0;
}