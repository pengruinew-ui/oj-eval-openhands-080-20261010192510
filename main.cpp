#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    if(!(cin >> n >> m)) return 0;
    vector<vector<int>> adj(n+1);
    vector<pair<int,int>> edges;
    edges.reserve(m);
    for(int i=0;i<m;++i){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edges.emplace_back(x,y);
    }
    vector<int> deg(n+1);
    for(int i=1;i<=n;++i) deg[i]=adj[i].size();
    vector<unordered_set<int>> adjSet(n+1);
    for(int i=1;i<=n;++i){
        adjSet[i].reserve(adj[i].size()*2);
        for(int v:adj[i]) adjSet[i].insert(v);
    }
    vector<char> inTri(n+1,false);
    for(auto &e: edges){
        int u=e.first, v=e.second;
        if(deg[u]>deg[v] || (deg[u]==deg[v] && u>v)) swap(u,v);
        for(int w: adj[u]){
            if(w==v) continue;
            if(adjSet[v].find(w)!=adjSet[v].end()){
                inTri[u]=inTri[v]=inTri[w]=true;
            }
        }
    }
    long long cnt=0;
    for(int i=1;i<=n;++i) if(!inTri[i]) ++cnt;
    cout<<cnt<<"\n";
    return 0;
}
