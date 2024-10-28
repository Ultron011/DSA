/*
    Sample Input - 
        "23"

    Sample Output -
        ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

#include<bits/stdc++.h>
using namespace std;

void solve(string digits, string output, int index, string mapping[], vector<string> &ans) {
    if (index >= digits.length()) {
        ans.push_back(output);
        return;
    }

    string ele = mapping[digits[index]-'0'];
    for (int i = 0; i< ele.length(); i++) {
        output.push_back(ele[i]);
        solve(digits, output, index+1, mapping, ans);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    string output;
    int index = 0;

    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", 
    "wxyz"};

    if (digits.length() == 0) {
        return ans;
    }

    solve(digits, output, index, mapping, ans);
    return ans;
}

int main () {

  string digits;
  cin >> digits;

  vector<string> ans = letterCombinations(digits);
  for (auto &s : ans) {
    cout << s << " ";
  }


  return 0;
}