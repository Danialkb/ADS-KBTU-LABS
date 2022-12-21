#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<int> > g1;
vector<vector<int> > g2;
int n;

int bfs(){
    queue<int> q;
    vector<bool> vis(n);   
    q.push(0);
    vector<int> d1(n);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0; i < g1[u].size(); i++){
            if(!vis[g1[u][i]]){
                q.push(g1[u][i]);
                vis[g1[u][i]] = true;
                d1[g1[u][i]] = d1[u] + 1;
            }
        }
    }
    vector<int> d2(n);
    vector<bool> vis1(n);
    queue<int> q2;
    q2.push(0);
    while(!q2.empty()){
        int u = q2.front();
        q2.pop();
        for(int i = 0; i < g2[u].size(); i++){
            int to = g2[u][i];
            if(!vis1[to]){
                // cout << "find!\n";
                q2.push(to);
                vis1[to] = true;
                d2[to] = d2[u] + 1;
            }
        }
    }
    // cout << d1[n - 1] << " " << d2[n - 1] << endl;
    if(d1[n - 1] == 0 || d2[n - 1] == 0)return INT_MAX;
    return max(d1[n - 1], d2[n - 1]);
}

int main() {
    int m;
    cin >> n >> m;
    g1.resize(n);
    g2.resize(n);
    map<pair<int, int>, bool > mapik;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g1[u].push_back(v);
        g1[v].push_back(u);
        mapik[make_pair(u, v)] = true;
        mapik[make_pair(v, u)] = true;
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(!mapik[make_pair(i, j)]){
                g2[i].push_back(j);
            }
        }
    }

    // for(int i = 0; i < g2.size(); i++) {
    //     for(int j = 0; j < g2[i].size(); j++)cout << g2[i][j] << ' ';
    //     cout << endl;
    // }

    if(bfs() == INT_MAX)cout << -1 << endl;
    else cout << bfs() << endl;


    return 0;
}