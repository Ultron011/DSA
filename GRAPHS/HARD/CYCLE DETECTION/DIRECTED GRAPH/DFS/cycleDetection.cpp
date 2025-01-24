#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity -  O(V+E)+O(V) , where V = no. of nodes and E = no. of edges. 
    Space complexity -  O(2N)
*/

class Solution {

    bool dfsCheck(int node, vector<int> &vis, vector<int> &pathVis, vector<int> adj[]) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]){
                if (dfsCheck(it, vis, pathVis, adj) == true) return true;
            } 
            else if (pathVis[it]) {
                return true;
            }
        }


        pathVis[node] = 0;
        return false;
    }

    public:
        bool isCyclic(int V, vector<int> adj[]) {
            vector<int> vis(V, 0);
            vector<int> pathVis(V, 0);

            for (int i = 0; i< V; i++) {
                if (!vis[i]) {
                    if (dfsCheck(i, vis, pathVis, adj)) return true;
                }
            }

            return false;
        }
};


int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}
