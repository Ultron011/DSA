/*
    Time complexity - 
        For storing as well as fetching - 
            O(log(n)) - Best , average and worst case

*/


#include<bits/stdc++.h>
using namespace std;

int main () {

  string s;
  cin >> s;

  map<char, int> mpp;
  for (int i = 0; i < s.length(); i++) {
    mpp[s[i]]++;
  }

/*
    Iterating over a map - 
    for (auto it: mpp) {
        cout << it.first << "->" << it.second << endl;
    }
*/
   
   int q;
   cin >> q;
   while(q--) {
    char c;
    cin >> c;
    cout << mpp[c] << endl;
   }


  return 0;
}