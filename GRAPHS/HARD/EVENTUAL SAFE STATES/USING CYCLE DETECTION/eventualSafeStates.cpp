#include <bits/stdc++.h>
using namespace std;


class Solution {
	bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis, vector<int>& mark) {
		vis[node] = 1;
		pathVis[node] = 1;
		mark[node] =0;

		for (auto it : adj[node]) {
			if (!vis[it]) {
				if (dfs(it, adj, vis, pathVis, mark)) {
					mark[node] = 0;
					return true;
				}
			}
			else if (pathVis[it]) {
				mark[node] = 0;
				return true;
			}
		}

		mark[node] = 1;
		pathVis[node] = 0;
		return false;
	}

public:
	vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
		vector<int> vis(V, 0);
		vector<int> pathVis(V, 0);
		
		vector<int> mark(V);
		vector<int> safeNodes;

		for (int i = 0; i < V; i++) {
			if (!vis[i]) {
				dfs(i, adj, vis, pathVis, mark);
			}
		}

		for (int i = 0; i < V; i++) {
			if (mark[i] == 1) safeNodes.push_back(i);
		}

		return safeNodes;
	}
};

int main() {

	vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		{8}, {9}
	};
	int V = 12;
	Solution obj;
	vector<int> safeNodes = obj.eventualSafeNodes(V, adj);

	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}