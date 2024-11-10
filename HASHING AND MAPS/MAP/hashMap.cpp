/*
    Time complexity - 
        For storing as well as fetching - 
            O(log(n)) - Best , average and worst case

*/


#include<bits/stdc++.h>
using namespace std;

int main () {

  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  map<int, int> mpp;
  for (int i =0; i < n; i++) {
    mpp[arr[i]]++;
  }

  int q;
  cin >> q;
  while (q--) {
    int num;
    cin >> num;

    cout << mpp[num] << endl;
  }




  return 0;
}