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
        set<pair<int, int>> st;
        vector<int> dist(V, INT_MAX);

        st.insert({0, S});
        dist[S] = 0;

        while (!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int currentDist = it.first;
            st.erase(it);

            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];

                if (currentDist + edgeWt < dist[adjNode]) {
                    // erase if it existed
                    if (dist[adjNode] != INT_MAX) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = currentDist + edgeWt;
                    st.insert({dist[adjNode], adjNode});
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