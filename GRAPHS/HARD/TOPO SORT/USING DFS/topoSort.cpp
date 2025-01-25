#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity - O(V + E)

    Space complexity - O(2N)
*/

class Solution {

    private:
    void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, st, adj);
            }
        }
        st.push(node);
    }

    public:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }

        vector<int> topo;
        for (int i = 0; i < V; i++) {
            topo.push_back(st.top());
            st.pop();
        }

        return topo;
    }
};


int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;
	Solution obj;
	vector<int> ans = obj.topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}