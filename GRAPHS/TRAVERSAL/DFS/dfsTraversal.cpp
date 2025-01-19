#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity -

    Space complexity -
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

  private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls) {
        vis[node] = 1;
        ls.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, adj, vis, ls);
            }
        }
    }

  public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        int start = 1;

        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }
    
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector <int> adj[9];
    
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 8);
    addEdge(adj, 8, 7);
    addEdge(adj, 3, 7);

    Solution obj;
    vector <int> ans = obj.dfsOfGraph(9, adj);
    printAns(ans);

    return 0;
}