/*
    Input - 
        [3, -1, -2, -5, 2, -4]
    
    Output - 
        [3, -1, 2, -2, -5, -4]
    
    Explanation - 
        The array elements should be rearranged in the same order in which they appear in the input 
        but with alternate sign elements right next to each other. In this question, 
        the number of positive and negtives will not be equal. So Add the remaining positive and 
        negative numbers at the end of the array without alterint its order.
*/

/*
    Time complexity - 
        O(2n)
    
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

    if (pos.size() > neg.size()) {
        for (int i = 0; i < neg.size(); i++) {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++) {
            arr[index] = pos[i];
            index++;
        }
    } else {
        for (int i = 0; i < pos.size(); i++) {
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++) {
            arr[index] = neg[i];
            index++;
        }
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