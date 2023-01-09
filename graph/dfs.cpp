#include <bits/stdc++.h>
using namespace std;

void solve(int node, vector<bool> &vis, unordered_map<int,vector<int>> &adj){
    if(vis[node])
    return;

    cout<<node<<" ";
    vis[node]=true;

    for(auto &x : adj[node]){
        solve(x,vis,adj);
    }
}

void dfs(int n, vector<vector<int>> &edges){
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n);
    
    solve(0,vis,adj);
}

int main(){
    int n;
    cin>>n;
    int size;
    cin>>size;
    vector<vector<int>> edges;
    for(int i=0;i<size;i++){
        vector<int> t;
        int u,v;
        cin>>u>>v;
        t.push_back(u);
        t.push_back(v);
        edges.push_back(t);
    }

    dfs(n,edges);
}