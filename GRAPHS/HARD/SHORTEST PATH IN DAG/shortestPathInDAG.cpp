#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(N+M) {for the topological sort} + O(N+M) {for relaxation of vertices, 
        each node and its adjacent nodes get traversed} ~ O(N+M).
        Where N= number of vertices and M= number of edges. 

    Space complexity -
        O( N) {for the stack storing the topological sort} + 
        O(N) {for storing the shortest distance for each node} + 
        O(N) {for the visited array} + O( N+2M) {for the adjacency list} ~ O(N+M) .

*/

class Solution {
    void topoSort(int node, vector<int> &vis, stack<int> &st, vector<vector<pair<int, int>>> &adj) {
        vis[node] = 1;

        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, vis, st, adj);
            }
        }

        st.push(node);
    }

  public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> adj(N);
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> vis(N, 0);
        stack<int> st;
        for (int i = 0; i < N; i++) {
            if (!vis[i]) {
                topoSort(i, vis, st, adj);
            }
        }

        vector<int> dist(N, 1e9);
        dist[0] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }

        }
        return dist;

    }
};

int main() {

  int N = 6, M = 7;
  
  vector<vector<int>> edges= {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
  Solution obj;
  vector < int > ans = obj.shortestPath(N, M, edges);

  for (int i = 0; i < ans.size(); i++) {

    cout << ans[i] << " ";
  }

  return 0;

}