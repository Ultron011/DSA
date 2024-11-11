/*
    Input - 
        [1, 1, 2, 3, 4, 5]
        [2, 3, 4 , 4, 5, 6]

    Output - 
        [1, 2, 3, 4, 5, 6]
*/

/*
     Time complexity - O(n1log(n) + n2log(n)) +  O(n1 + n2)
     Space Complexity - O(n1 + n2) + O(n1 + n2)
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> unionOfSortedArrays(vector<int> A, vector<int> B) {
    set<int> st;
    for (int i = 0; i < A.size(); i++) {
        st.insert(A[i]);
    }
    for (int i = 0; i < B.size(); i++) {
        st.insert(B[i]);
    }

    vector<int> temp;
    for (auto it : st) {
        temp.push_back(it);
    }
    return temp;
}

void printArray(vector<int> arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main () {

  int n1, n2;
  cin >> n1 >> n2;
  vector<int> A(n1);
  vector<int> B(n2);

  for (int i = 0; i < n1; i++) cin>> A[i];
  for (int i = 0; i < n2; i++) cin>> B[i];

  vector<int> ans = unionOfSortedArrays(A, B);

  printArray(ans);

  return 0;
}