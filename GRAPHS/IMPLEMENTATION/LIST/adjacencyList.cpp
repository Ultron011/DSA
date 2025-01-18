#include<bits/stdc++.h>
using namespace std;

/*
    Space complexity - O(2*E)
*/ 

int main() {

  int n, m;
  cin >> n >> m;

  vector<int> adj[n+1]; // vector<pair<int, int>> adj[n+1] in case of weighted graph where pair contains adjacent node and edge weight

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  return 0;
}