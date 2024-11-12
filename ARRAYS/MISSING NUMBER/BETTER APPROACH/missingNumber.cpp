/*
    Time Complexity - 
        O(n)
    Space Complexity - 
        O(n)
*/

#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> arr, int n) {
    vector<int> hash(n+1, 0);
    for (int i = 0; i < arr.size(); i++) {
        hash[arr[i]] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n-1);
  for (int i = 0; i < n-1; i++) {
    cin >> arr[i];
  }

  cout << "The missing Number is : " << missingNumber(arr, n) << endl;

  return 0;
}