/*
    Given a list of numbers, return the number that appears strictly more than (N/2) times in the list where N is the 
    length of the list. The number that appears more than N/2 times is called the majority number.

    Input -
        [2, 2, 3, 3, 1, 2, 2]
    Output - 
        2
    Explanation - 
        N = 7, N/2 = 3 . In the given list , 2 appears more than 3 times, so 2 is the majority element.
*/

/*
    Moore's Voting Algorithm

    Time complexity - 
        O(n)
    Space complexity - 
        O(1)
*/


#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> arr) {
    int cnt = 0;
    int el;
    for (int i = 0; i < arr.size(); i++) {
        if (cnt == 0) {
            cnt = 1;
            el = arr[i];
        }
        else if (arr[i] == el) {
            cnt++;
        }
        else {
            cnt--;
        }
    }

    int cnt1 = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == el) {
            cnt1++;
        }
    }
    
    if (cnt1 > (arr.size())/ 2) {
        return el;
    }
    return -1;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Majority Element is : " << majorityElement(arr) << endl;

  return 0;
}