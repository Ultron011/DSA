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
    O(n^2)
  Space complexity - 
    O(1)
*/

#include<bits/stdc++.h>
using namespace std;

pair<int, int> twoSum(vector<int> arr, int targetSum) {
    for (int i = 0; i < arr.size(); i++) {
      for (int j = i + 1; j < arr.size(); j++) {
        if (arr[i] + arr[j] == targetSum) {
          return {i, j};
        }
      }
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