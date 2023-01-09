#include <bits/stdc++.h>
using namespace std;

void bfs(int n, vector<vector<int>> &edges){
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }    
    queue<int> q;
    q.push(0);
    
    vector<bool> vis(n);
    vis[0]=true;
    
    while(!q.empty()){
        int size = q.size();
        while(size--){
            int node = q.front();
            cout<<node<<" ";
            q.pop();

            for(auto &x : adj[node]){
                if(!vis[x]){
                    vis[x]=true;
                    q.push(x);
                }
            }
        }
    }
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

    bfs(n,edges);
}