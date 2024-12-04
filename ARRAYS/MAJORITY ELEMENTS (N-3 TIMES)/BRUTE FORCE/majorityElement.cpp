/*
    Given a list of numbers, return the number that appears strictly more than (N/3) times in the list where N is the 
    length of the list. The number that appears more than N/3 times is called the majority number.

    Input -
        [2, 2, 3, 3, 1, 2, 2, 3]
    Output - 
        2, 3
    Explanation - 
        N = 7, N/3 = 2 . In the given list , 2 and 3 appears more than 2 times, so 2 and 3 are the majority elements.
*/

/*
    Time complexity - 
        O(n^2)
    Space complexity - 
        O(1)
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> arr) {
    int n = arr.size();
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (res.size() == 0 || res[0] != arr[i]) {
            int cnt = 0;
            for (int j = 0;j < n; j++) {
                if (arr[i] == arr[j]) {
                    cnt++;
                }
            }
            if (cnt > n/3) {
                res.push_back(arr[i]);
            }
        }
        if (res.size() == 2) {
            break;
        }
    }

    return res;

}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  
  vector<int> ans = majorityElement(arr);
  cout << "Majority Element is : ";
  for (auto it : ans) {
    cout << it << " ";
  }

  return 0;
}