#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity -  O(V+E)+O(V) , where V = no. of nodes and E = no. of edges. 
    Space complexity -  O(2N)
*/

class Solution {
    public:
        bool isCyclic(int V, vector<int> adj[]) {
            vector<int> indegree(V, 0);
            for (int i = 0; i < V; i++) {
                for (auto it : adj[i]) {
                    indegree[it]++;
                }
            }

            queue<int> q;
            for (int i = 0; i < V; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }

            int cnt = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                cnt++;

                for  (auto it : adj[node]) {
                    indegree[it]--;
                    if (indegree[it] == 0) q.push(it);
                }
            }

            if (cnt == V) return false;
            return true;


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
