#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string> &wordList)
    {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;

        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();

            // erase all the words that have been used in the previous levels to transform
            if (vec.size() > level) {
                level++;
                for (auto it : usedOnLevel) {
                    st.erase(it);
                }
                usedOnLevel.clear();
            }

            string word = vec.back();
            if (word == endWord) {
                if (ans.size() == 0) {
                    ans.push_back(vec);
                } else if (ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                }
            }
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a' ; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }

        return ans;
    }
};


int main()
{

    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
    Solution obj;
    vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
    
    // If no transformation sequence is possible.
    if (ans.size() == 0)
        cout << -1 << endl;
    else
    {
        for (auto list : ans) {
            for (string s : list) {
                cout << s << " ";
            }
            cout << endl;
        }
    }

    return 0;
}