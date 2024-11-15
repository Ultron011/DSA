/*
    Input - 
        [-2, -3, 4, -1, -2, 1, 5, -3]
    Ouput - 
        7
*/

/*
    Time complexity - 
        O(n^2)
    Space complexity -
        O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int maximumSubarraySum(vector<int> arr) {
    int maxi = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}


int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << maximumSubarraySum(arr) << endl;

  return 0;
}