/*
  Input - 
    10 - (len of array)
    [1, 2, 3, 1, 1, 1, 1, 4, 2, 3]
    3 - (Sum k)
  
  Output - 
    3

  Explanation - 
    Subarrays with sum 3 - (1, 2) , (1, 1, 1)
    The length of subarray with max elements is 3 i.e.(1, 1, 1) . So the output is 3.
*/

/*
  Time complexity - 
    O(n^3)
  Space Complexity -
    O(1)
*/



#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> arr, int k) {
  int len = 0;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = i; j < arr.size(); j++) {
      int s = 0;
      for (int k = i; k <= j; k++) {
        s += arr[k];
      }
      if (s == k) {
        len = max(len, j - i + 1);
      }
    }
  }
  return len;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int k;
  cin >> k;

  cout << "Length of longest subarray with sum " << k << " is : " << longestSubarray(arr, k) << endl;

    

  return 0;
}