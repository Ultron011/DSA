#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(N + 2E)
    
    Space complexity -
        O(N)
*/

class Solution {

    bool detect(int node, int parent, int vis[], vector<int> adj[]) {
        vis[node] = 1;
        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                if (detect(adjNode, node, vis, adj)) return true;
            }
            else if (adjNode != parent) return true;
        }
        return false;
    }

    public:
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V] = {0};

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, -1, vis, adj)) return true;
            }
        }

        return false;
    }
};

int main() {
    
    // V = 4, E = 2
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}