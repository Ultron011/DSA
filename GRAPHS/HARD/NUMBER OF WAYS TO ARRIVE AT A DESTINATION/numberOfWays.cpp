#include <bits/stdc++.h>
using namespace std;

/*
    Time complexity - O (E(log(V)))
    Space complexity - O(V)
*/

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
         vector<vector<pair<int, int>>> adj(n);
         for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
         }

         // Min heap priority queue
         priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq;
         pq.push({0, 0});

         vector<int> dist(n, 1e9);
         dist[0] = 0;
         vector<int> ways(n, 0);
         ways[0] = 1;
         
         // This mod is requirement of the question , nothing to do with logic
         int mod = (int)(1e9 + 7);

         while (!pq.empty()) {
            auto it = pq.top();
            int dis = it.first;
            int node = it.second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;
                // first time arriving to the node
                if (dis + edgeWt < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dis + edgeWt, adjNode});
                    ways[adjNode] = ways[node];
                }
                else if (dis + edgeWt == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            } 
         }

         return ways[n-1] % mod;


    }
};

int main()
{
    // Driver Code.
    int n = 7;

    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, 
    {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    Solution obj;

    int ans = obj.countPaths(n, edges);

    cout << ans;
    cout << endl;

    return 0;
}