#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
    bool check(int start, int V, vector<int> adj[], vector<int> &color) {
		queue<int> q;
		q.push(start);
		color[start] = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (auto adjNodes : adj[node]) {
				if (color[adjNodes] == -1) {
					color[adjNodes] = !color[node];
					q.push(adjNodes);
				} else if (color[adjNodes] == color[node]) {
					return false;
				}
			}
		}

		return true;
	}
public:
	bool isBipartite(int V, vector<int>adj[]){
		vector<int> color(V, -1);

		// For graph with mulitple components
		for (int i = 0; i < V; i++) {
			if (color[i] == -1) {
				if (check(i, V, adj, color) == false) {
					return false;
				}
			}
		}

		return true;
	}
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
	
	// V = 4, E = 4
	vector<int>adj[4];
	
	addEdge(adj, 0, 2);
   	addEdge(adj, 0, 3);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 1);

	Solution obj;
	bool ans = obj.isBipartite(4, adj);    
	if(ans)cout << "1\n";
	else cout << "0\n";  
	
	return 0;
}