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
        O(n)
    Space complexity - 
        O(n)
*/

/*
    Time complexity - 
        O(n)
    Space complexity - 
        O(1)
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> arr) {
    int n = arr.size();
    int cnt1 = 0, cnt2 = 0;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && arr[i] != el2) {
            cnt1 = 1;
            el1 = arr[i];
        }
        else if (cnt2 == 0 && arr[i] != el1) {
            cnt2 = 1;
            el2 = arr[i];
        }
        else if (el1 == arr[i]) cnt1++;
        else if (el2 == arr[i]) cnt2++;
        else {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ls;
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == el1) cnt1++;
        else if(arr[i] == el2) cnt2++;
    }

    if (cnt1 > n/3) ls.push_back(el1);
    if (cnt2 > n/3) ls.push_back(el2);
    return ls;

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