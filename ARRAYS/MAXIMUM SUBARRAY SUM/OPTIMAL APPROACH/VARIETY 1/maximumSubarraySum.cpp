/*
            Kadane's Algorithm
    Input - 
        [-2, -3, 4, -1, -2, 1, 5, -3]
    Ouput - 
        7
*/

/*
    Time complexity - 
        O(n)
    Space complexity -
        O(1)
*/

#include<bits/stdc++.h>
using namespace std;

int maximumSubarraySum(vector<int> arr) {
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum = sum + arr[i];
        if (sum > maxi) {
            maxi = sum;
        }
        if (sum < 0) {
            sum = 0;
        }
    }

    if (maxi < 0) {
        return 0;
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