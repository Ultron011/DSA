/*
    Input - 
        [1, 1, 0, 1, 1, 1, 0, 1 , 1]

    Output - 
        3

    Explanation - Since there are maximum three consective ones in the array , so the result is 3.

*/

/*
    Time complexity - 
        O(n)
    Space complexity - 
        O(1)

*/


#include<bits/stdc++.h>
using namespace std;

int maximumConsecutiveOnes(vector<int> arr) {
    int maxi = 0;
    int cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 1) {
            cnt++;
            maxi = max(maxi, cnt);
        } else {
            cnt = 0;
        }
    }
    return maxi;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Maximum Consective Ones is : " << maximumConsecutiveOnes(arr) << endl;

  return 0;
}