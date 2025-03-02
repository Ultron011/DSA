/*
    Sample Input - 
        [a , b, c]

    Sample Output -
        [{}, {a}, {b}, {c}, {a, b}, {b, c}, {c, a}, {a, b, c}]
*/

#include<bits/stdc++.h>
using namespace std;

void solve(string str, string output, int index, vector<string>&ans) {
    if (index >= str.size()) {
        ans.push_back(output);
        return;
    }

    solve(str, output, index+1, ans);

    char ele = str[index];
    output.push_back(ele);
    solve(str, output, index+1, ans);
}

vector<string> subsequences(string str) {
    vector<string> ans;
    string output = "";
    int index = 0;

    solve(str, output, index, ans);
    return ans;
}

int main () {

  string str = "abc";

  vector<string> sub = subsequences(str);

  for (int i =0; i < sub.size(); i++) {
    cout << "[" << sub[i] << "]" << " ";
  }

  return 0;
}