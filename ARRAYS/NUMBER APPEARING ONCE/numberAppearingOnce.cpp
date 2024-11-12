/*
    Input - 
        [1, 1, 2, 3, 3, 4 , 4]

    Output - 
        2

    Explanation - Since the only number that appears once is 2 , so the output would be 2.
*/

/*
    Time complexity - 
        O(n)
    Space complexity - 
        O(1)

*/


#include<bits/stdc++.h>
using namespace std;

int numberAppearingOnce(vector<int> arr) {
    int ans = 0;
    for (int i = 0; i < arr.size(); i++) {
        ans ^= arr[i];
    }
    return ans;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Element appearing once is : " << numberAppearingOnce(arr) << endl;

  return 0;
}