#include<bits/stdc++.h>
using namespace std;

/*
    Time complexity - O( E log(V) ) 

    Space complexity - O( |E| + |V| ) 
*/

class Solution
{   
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Initialize distances with infinity
        vector<int> dist(V, INT_MAX);
        dist[S] = 0; // Distance to the source node is 0

        // Min-heap priority queue to store {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S}); // Push the source node with distance 0

        while (!pq.empty()) {
            int currentDistance = pq.top().first; // Distance to the current node
            int currentNode = pq.top().second; // Current node
            pq.pop();

            // Skip if we've already found a better path to this node
            if (currentDistance > dist[currentNode]) {
                continue;
            }

            // Explore all neighbors of the current node
            for (const auto& edge : adj[currentNode]) {
                int neighborNode = edge[0]; // Neighbor node
                int edgeWeight = edge[1]; // Weight of the edge to the neighbor

                // Relaxation step
                if (currentDistance + edgeWeight < dist[neighborNode]) {
                    dist[neighborNode] = currentDistance + edgeWeight;
                    pq.push({dist[neighborNode], neighborNode});
                }
            }
        }

        return dist;
    }
};

int main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;
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
    vector<int> res = obj.dijkstra(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}