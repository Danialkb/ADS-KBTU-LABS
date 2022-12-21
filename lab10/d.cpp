#include <bits/stdc++.h>
using namespace std;
int n, m, q;
vector<vector<int> > g;
vector<int> color;
vector<bool> vis;
void bfs(int v){
    if(color[v] == 1){
        cout << 0 << endl;
        return;
    }
    queue<int> q;
    q.push(v);
    vis[v] = true;
    int dis = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        dis++;
        for(int i = 0; i < g[u].size(); i++){
            int to = g[u][i];
            if(!vis[to]){
                if(color[to] == 1){
                    cout << dis << endl;
                    return;
                }
                q.push(to);
                vis[to] = true;
            }
        }
    }
    cout << -1 << endl;
} 
int main() {
    // freopen ("input.txt" , "r", stdin);
    // freopen ("output.txt" , "w", stdout);
    cin >> n >> m >> q;
    g.resize(n);
    color.resize(n);
    vis.resize(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    while(q--){
        int c, ver;
        cin >> c >> ver;
        ver--;
        if(c == 1){
            color[ver] = 1;
        }
        else{
            bfs(ver);
            vis.assign(n, false);
        }
    }


    return 0;
}