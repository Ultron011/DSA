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
    O(nlog(n))
  Space Complexity -
    O(n)

    It is the optimal solution if array contains positive , negative numbers as well as zero.
*/



#include<bits/stdc++.h>
using namespace std;

long long longestSubarray(vector<int> arr, int k) {
  map<long long, int> preSumMap;
  long long sum = 0;
  int maxLen = 0;

  for (int i = 0; i < arr.size(); i++) {
    sum += arr[i];
    if (sum == k) {
        maxLen = max(maxLen, i + 1);
    }
    long long rem = sum - k;
    if (preSumMap.find(rem) != preSumMap.end()) {
        int len = i - preSumMap[rem];
        maxLen = max(maxLen, len);
    }
    if (preSumMap.find(sum) == preSumMap.end()) {
        preSumMap[sum] = i;
    }
  }

  return maxLen;
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