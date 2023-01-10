#include <bits/stdc++.h>
using namespace std;

void secondDegree(vector<vector<int>> &edges, int n){
    unordered_map<int,vector<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        cout<<i<<" -> ";
        vector<bool> vis(n+1, false);;
        for(auto &x : adj[i]){
            for(auto &neigh : adj[x]){
                if(!vis[neigh] && neigh!=i){
                    cout<<neigh<<" ";
                    vis[neigh]=true;
                }
            }
        }
        cout<<endl;
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

    secondDegree(edges,n);
}