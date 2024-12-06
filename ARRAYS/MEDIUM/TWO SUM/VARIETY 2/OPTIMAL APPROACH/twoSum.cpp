/*
    Question - 
        Given a list of numbers, return "YES" if target sum can be obtained by adding any two numbers , otherwise return "NO"
    Input - 
        [2, 6, 5, 8, 11]
        14 - (target Sum)
    
    Output - 
        1 3

    Explanation - 6 + 8 = 14 , so the output is yes.
*/

/*
  Time complexity - 
    O(nlog(n))
  Space complexity - 
    O(n)
*/

#include<bits/stdc++.h>
using namespace std;

pair<int, int> twoSum(vector<int> arr, int targetSum) {
    int n = arr.size();
    map<int, int> mpp;
    for (int i  = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = targetSum - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int targetSum;
  cin >> targetSum;

  pair<int, int> ans = twoSum(arr, targetSum);
  cout << ans.first << " " << ans.second << endl;

  return 0;
}