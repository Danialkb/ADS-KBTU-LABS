#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<bool> vis;
void dfs(int v, int d){
    vis[v] = true;
    for(int i = 0; i < g[v].size(); i++){
        if(!vis[g[v][i]]){
            dfs(g[v][i], d);
        }
    }
}   
int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    vis.resize(n);
    for(int i  = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }

    int s, f;
    cin >> s >> f;
    s--, f--;
    dfs(s, f);
    cout << ((vis[f]) ? "YES\n" : "NO\n");

    return 0;
}