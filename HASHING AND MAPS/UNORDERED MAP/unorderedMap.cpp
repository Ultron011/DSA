/*
    Map sorts the key value pair to store them , while unordered map randomly 
    stores the key value pair, there is no concept of sorting.

    Time complexity - 
        For storing as well as fetching - 
            O(1) - For best and average case
            O(n) - Worst Case (when hash function is not good)

*/

#include<bits/stdc++.h>
using namespace std;

int main () {

  string s;
  cin >> s;

  unordered_map<char, int> mpp;
  for (int i = 0; i < s.length(); i++) {
    mpp[s[i]]++;
  }

/*
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