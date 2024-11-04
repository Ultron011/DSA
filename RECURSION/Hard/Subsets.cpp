/*
    Sample Input - 
        nums = [1, 2, 3]
    
    Sample Outupt - 
        [{}, {1}, {2}, {3}, {1, 2}, {2, 3}, {1, 3}, {1, 2, 3}]

    Explanation - 
        Give all possible subsets of given input array.
*/

#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<int> out, int index, vector<vector<int>> &ans) {
    if (index >= nums.size()) {
        ans.push_back(out);
        return;
    }

    // exclude
    solve(nums, out, index + 1, ans);
    
    // include
    int element = nums[index];
    out.push_back(element);
    solve(nums, out, index+1, ans);
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> out;
    int index = 0;
    solve(nums, out, index, ans);
    return ans;
}

int main () {

  vector<int> nums = {1, 2, 3};

  vector<vector<int>> sub = subsets(nums);

  	for(int i=0;i<sub.size();i++){
        cout << "[";
		for(int j=0;j<sub[i].size();j++)
			cout<<sub[i][j]<<" ";
		cout<< "]";
	}


  return 0;
}

