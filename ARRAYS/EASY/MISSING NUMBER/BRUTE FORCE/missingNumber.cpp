/*
    Time Complexity - 
        O(n^2)
    Space Complexity - 
        O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> arr, int n) {
    for (int i = 1; i <= n; i++) {
        int numberPresent = 0;
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] == i) {
                numberPresent = 1;
                break;
            }
        }
        if (!numberPresent) {
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