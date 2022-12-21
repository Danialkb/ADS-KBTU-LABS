#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int root =  1e9;
vector<vector<int> > g;
vector<bool> vis;
void bfs(int v){
    vis[v] = true;
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        // if(u == root)cnt++;
        for(int i = 0; i < g[u].size(); i++){
            if(!vis[g[u][i]]){
                q.push(g[u][i]);
                vis[g[u][i]] = true;
                if(g[u].size() < g[g[u][i]].size())cnt++;
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    vis.resize(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        // g[v].push_back(u);
        if(u < root)root = u;
        if(v < root)root = v;
    }
    // cout << root << endl;
    // cnt = g[root].size();
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            cnt++;
            bfs(i);
        }
    }
    cout << cnt << endl;
    return 0;
}