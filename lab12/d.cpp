#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, long long> > > g;

bool bfs(long long pred, int n){
    queue<int> q;
    vector<bool> vis(n);
    q.push(0);
    vis[0] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        if(v == n - 1)return true;
        for(int i = 0; i < g[v].size(); i++){
            int to = g[v][i].first;
            long long cost = g[v][i].second;
            if(!vis[to] && pred >= cost){
                vis[to] = true;
                q.push(to);
            }
        }
    }
    return false;
}

int main() {
    // freopen ("input.txt" , "r", stdin);
    // freopen ("output.txt" , "w", stdout);
    int n;
    cin >> n;
    g.resize(n);
    vector<pair<long long, long long> > coords;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        coords.push_back(make_pair(x, y));
    }

    if(n == 1){
        cout << 0;
        return 0;
    }
    // cout << endl;
    // for(int i = 0; i < coords.size(); i++)cout << coords[i].first << ' ' << coords[i].second << endl;
    for(int i = 0; i < coords.size(); i++){
        for(int j = i + 1; j < coords.size(); j++){
            g[i].push_back(make_pair(j, (abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second))));
            g[j].push_back(make_pair(i, (abs(coords[i].first - coords[j].first) + abs(coords[i].second - coords[j].second))));
        }
    }
    // for(int i = 0; i < g.size(); i++){
    //     for(int j = 0; j < g[i].size(); j++){
    //         cout << i + 1 << ' ' << g[i][j].first + 1 << ' ' << g[i][j].second << endl;
    //     }
    // }
    long long res = -1, left = 1, right = 2 * 1e9, mid;
    
    while(left <= right){
        mid = (right + left) / 2;
        if(bfs(mid, n)){
            right = mid - 1;
            res = mid;
        }
        else {
            left = mid + 1;
        }
    }
    
    cout << res << endl;

    return 0;
}