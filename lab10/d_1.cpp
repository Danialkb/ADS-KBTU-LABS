#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<int> color;
// vector<bool> vis;
vector<int> dis;
void bfs(int v){
    queue<int> q;
    q.push(v);
    dis[v] = 0;
    // vis[v] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < g[u].size(); i++){
            int to = g[u][i];
            if(dis[to] > dis[u] + 1){
                dis[to] = dis[u] + 1;
                // vis[to] = true;
                q.push(to);
            }
        }
    }
} 
int main() {
    // freopen ("input.txt" , "r", stdin);/
    freopen ("output.txt" , "w", stdout);
    int n, m, q;
    cin >> n >> m >> q;
    g.resize(n + 1);
    color.resize(n + 1);
    // vis.resize(n);
    dis.assign(n + 1, 1e9);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        // u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < q; i++){
        int c, ver;
        cin >> c >> ver;
        // ver--;
        if(c == 1){
            if(color[ver] == 0){
                // vis.assign(n, false);
                bfs(ver);
                color[ver] = 1;
            }
        }
        else{
            if(dis[ver] == 1e9){
                cout << -1 << endl;
            }else cout << dis[ver] << endl;
        }
        
        for(int j = 0; j < n; j++)cout << dis[j] << ' ';
        cout << endl;

    }
    
    return 0;
}