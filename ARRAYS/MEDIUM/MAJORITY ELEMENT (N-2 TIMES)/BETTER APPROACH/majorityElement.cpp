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
    Time complexity - 
        O(nlog(n))
    Space complexity - 
        O(1)
*/


#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> arr) {
    int n = arr.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    for (auto it : mpp) {
        if (it.second > n / 2) {
            return it.first;
        }
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