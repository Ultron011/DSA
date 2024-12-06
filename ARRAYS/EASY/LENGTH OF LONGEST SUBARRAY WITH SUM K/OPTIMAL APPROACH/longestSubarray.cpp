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
    O(2n)
  Space Complexity -
    O(1)

    It is the optimal solution when array contain only positive numbers or zero.
*/



#include<bits/stdc++.h>
using namespace std;


int longestSubarray(vector<int> arr, int k) {
  int left = 0, right = 0;
  long long sum = arr[0];
  int maxLength = 0;
  int n = arr.size();
  while (right < n) {
    while (left <=right && sum > k) {
      sum -= arr[left];
      left++;
    }
    if (sum == k) {
      maxLength = max(maxLength, right - left + 1);
    }
    right++;
    if (right < n) {
      sum += arr[right];
    }
  }
  return maxLength;
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