#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<int> color;
vector<bool> vis;
vector<int> res;
bool cycle(int v){
    color[v] = 1;
    // cout << v + 1 << " ";
    for(int i = 0; i < g[v].size(); i++){
        if(color[g[v][i]] == 0 && cycle(g[v][i]))return true;
        if(color[g[v][i]] == 1)return true;
    }
    color[v] = 1e6;
    return false;
}

void dfs(int v){
    vis[v] = true;
    // cout << v + 1 << " ";
    for(int i = 0; i < g[v].size(); i++){
        if(!vis[g[v][i]])dfs(g[v][i]);
    }
    res.push_back(v + 1);
}

int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    color.resize(n);
    vis.resize(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        // g[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
        if(cycle(i)){
            cout << "Impossible\n";
            return 0;
        }
    }

    cout << "Possible\n";
    for(int i = 0; i < n; i++){
        if(!vis[i])dfs(i);
    }

    for(int i = res.size() - 1; i >= 0; i--)cout << res[i] << " ";

    return 0;
}