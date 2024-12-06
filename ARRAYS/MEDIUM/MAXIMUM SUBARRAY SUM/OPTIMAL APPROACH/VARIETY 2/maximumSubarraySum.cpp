/*
            Kadane's Algorithm
    Input - 
        [-2, -3, 4, -1, -2, 1, 5, -3]
    Ouput - 
        [4, -1, -2, 1, 5]
*/

/*
    Time complexity - 
        O(n)
    Space complexity -
        O(1)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> maximumSubarraySum(vector<int> arr) {
    int maxi = INT_MIN;
    int sum = 0;
    int ansStart = -1, ansEnd = -1;
    int start = -1;
    for (int i = 0; i < arr.size(); i++) {
        if (sum == 0) {
            start = i;
        }
        sum = sum + arr[i];
        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0) {
            sum = 0;
        }
    }

    if (maxi < 0) {
        return {0};
    }

    return {arr.begin() + ansStart, arr.begin() + ansEnd + 1};

}


int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> res= maximumSubarraySum(arr);
  for (auto it : res) {
    cout << it << " ";
  }

  return 0;
}