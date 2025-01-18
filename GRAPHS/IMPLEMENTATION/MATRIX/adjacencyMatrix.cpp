#include<bits/stdc++.h>
using namespace std;

/*
    Space complexity - O(N^2)
*/ 

int main() {
  
  /* n - no. of nodes
     m - no. of edges
  */
  int n, m;
  cin >> n >> m;

  int adj[n+1][n+1];

  for  (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u][v] = 1; // store edge weight instead of 1 in case of weighted graph
    adj[v][u] = 1;
  }

  return 0;
}