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
        O(n+n/2)
    
    Space complexity -
        O(n)
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> arrangeBySign(vector<int> arr) {
    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i< arr.size(); i++) {
        if (arr[i] >= 0) {
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }

    for (int i = 0; i < arr.size()/ 2; i++) {
        arr[2*i] = pos[i];
        arr[(2*i) + 1] = neg[i];
    }
    return arr;
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