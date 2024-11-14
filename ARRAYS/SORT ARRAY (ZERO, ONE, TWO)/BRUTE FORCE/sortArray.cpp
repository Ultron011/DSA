/*
    Input - 
        [0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1]
    Output - 
        [0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2]
*/

/*
    Time complexity - 
        O(nlog(n))
    Space complexity 0 
        O(1)
*/

#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    } 
    cout << endl;
}

int main () {

  int n;
  cin >> n;
  vector<int> arr(n);
  for(int i =0; i < n; i++) {
    cin >> arr[i];
  }
  
  printArray(arr);
  sort(arr.begin(), arr.end());
  printArray(arr);


  return 0;
}