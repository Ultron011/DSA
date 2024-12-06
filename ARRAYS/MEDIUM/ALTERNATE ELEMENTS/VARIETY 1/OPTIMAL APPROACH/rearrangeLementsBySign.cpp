/*
    Input - 
        [3, 1, -2, -5, 2, -4]
    
    Output - 
        [3, -2, 1, -5, 2, -4]
    
    Explanation - 
        The array elements should be rearranged in the same order in which they appear in the input 
        but with alternate sign elements right next to each other. In this question, 
        the number of positive and negative will be equal.
*/

/*
    Time complexity - 
        O(n)
    
    Space complexity -
        O(n)
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> arrangeBySign(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n, 0);

    int posIndex = 0;
    int negIndex = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0){
            ans[posIndex] = arr[i];
            posIndex += 2;
        } else {
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }
    return ans;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);

  for(int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  vector<int> ans = arrangeBySign(arr);

  for (auto i : ans) {
    cout << i << " ";
  }

  return 0;
}