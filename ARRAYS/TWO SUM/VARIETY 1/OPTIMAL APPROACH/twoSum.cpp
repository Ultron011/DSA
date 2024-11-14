/*
    Question - 
        Given a list of numbers, return "YES" if target sum can be obtained by adding any two numbers , otherwise return "NO"
    Input - 
        [2, 6, 5, 8, 11]
        14 - (target Sum)
    
    Output - 
        Yes

    Explanation - 6 + 8 = 14 , so the output is yes.
*/

/*
  Time complexity - 
    O(nlog(n))
  Space complexity - 
    O(1)
*/

#include<bits/stdc++.h>
using namespace std;

bool twoSum(vector<int> arr, int targetSum) {
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int currentSum = arr[left] + arr[right];
        if (currentSum == targetSum) {
            return true;
        }
        else if (currentSum < targetSum) {
            left += 1;
        } else {
            right -= 1;
        }
    }
    return false;
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

  if (twoSum(arr, targetSum)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}