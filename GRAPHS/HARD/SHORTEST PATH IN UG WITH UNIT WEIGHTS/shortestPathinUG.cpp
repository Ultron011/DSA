#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity - 
        O(M) { for creating the adjacency list from given list ‘edges’} + O(N + 2M) { for the BFS Algorithm} + O(N) 
        { for adding the final values of the shortest path in the resultant array} ~ O(N+2M), Where N= number of vertices and M= number of edges.

    Space complexity -
        O( N) {for the stack storing the BFS} + O(N) {for the resultant array} + O(N) 
        {for the dist array storing updated shortest paths} + O( N+2M) {for the adjacency list} ~ O(N+M) .
*/

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adj(N);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> dist(N, 1e9);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (dist[node] + 1 < dist[it]) {
                    dist[it] = dist[node]+ 1;
                    q.push(it);
                }
            }
        }

        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++) {
            if (dist[i] != 1e9) {
                ans[i] = dist[i];
            }
        }

        return ans;
    }
};

int main(){

int N=9, M=10;
vector<vector<int>> edges= {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};

Solution obj;
vector<int> ans = obj.shortestPath(edges,N,M,0);

for(int i=0;i<ans.size();i++){
    
    cout<<ans[i]<<" ";
}

return 0;
}