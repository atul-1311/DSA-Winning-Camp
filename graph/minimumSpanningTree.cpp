#include <bits/stdc++.h>
using namespace std;

class Disjoint{
    vector<int> rank, parent;

    public:
    Disjoint(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int ultParent(int node){
        if(node==parent[node])
        return node;

        return parent[node] = ultParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ult_paru = ultParent(u);
        int ult_parv = ultParent(v);

        if(ult_paru==ult_parv)
        return;

        if(rank[ult_paru] < rank[ult_parv]){
            parent[ult_paru] = ult_parv;
        }
        else if(rank[ult_paru] > rank[ult_parv]){
            parent[ult_parv] = ult_paru;
        }
        else{
            parent[ult_parv]=ult_paru;
            rank[ult_paru]++;
        }
    }
};

int minimumSpanningTree(int n, vector<vector<int>> &edges){

    Disjoint dj(n);

    vector<pair<int, pair<int,int>>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj.push_back(make_pair(w, make_pair(u,v)));
    }
    sort(adj.begin(),adj.end());

    int ans=0;

    for(int i=0;i<adj.size();i++){
        int u = adj[i].second.first;
        int v = adj[i].second.second;
        int w = adj[i].first;
        if(dj.ultParent(u)!=dj.ultParent(v)){
            ans+=w;
            dj.unionByRank(u,v);
        }
    }

    return ans;
}

int main(){
    int n;
    cin>>n;
    int size;
    cin>>size;

    vector<vector<int>> edges;
    for(int i=0;i<size;i++){
        vector<int> t;
        int u,v,w;
        cin>>u>>v>>w;
        t.push_back(u);
        t.push_back(v);
        t.push_back(w);
        edges.push_back(t);
    }

    int mst = minimumSpanningTree(n,edges);
    cout<<mst;
}