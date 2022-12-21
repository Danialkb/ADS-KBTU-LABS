#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<bool> vis;
vector<int> dis;
int cnt = 1;
void bfs(int v, int end){
    queue<int> q;
    q.push(v);
    vis[v] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(u == end)break;
        for(int i = 0; i < g[u].size(); i++){
            if(!vis[g[u][i]]){
                q.push(g[u][i]);
                vis[g[u][i]] = true;
                dis[g[u][i]] = dis[u] + 1;
            }
        }
    }
} 
int main() {
    int n;
    cin >> n;
    g.resize(n);
    vis.resize(n);
    dis.resize(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int x;
            cin >> x;
            if(x == 1){
                g[i].push_back(j);
            }
        }
    }
    int s, e;
    cin >> s >> e;
    s--, e--;
    bfs(s, e);
    cout << ((dis[e] == 0) ? -1 : dis[e]) << endl;
    return 0;
}