#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O( E log(V) ) 

    Space complexity - O( |E| + |V| ) 
*/

class Solution
{   
	public:
    vector <int> shortestPath(int V, vector<vector<int>> adj[], int S, int D)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>>> pq; // min heap priority queue
        pq.push({0, S});

        vector<int> dist(V, 1e9);
        dist[S] = 0;
        vector<int> parent(V);
        for (int i =0; i < V; i++) parent[i] = i;
        
        while (!pq.empty()) {
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];
                if (dis + edgeWt < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        if (dist[V] == 1e9) {
            return {-1};
        } 
        vector<int> path;
        int node = D;
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(S);
        reverse(path.begin(), path.end());
        return path;
    }
};

int main()
{
    // Driver code.
    int V = 3, E = 3, S = 1, D = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    vector<int> res = obj.shortestPath(V, adj, S, D);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}