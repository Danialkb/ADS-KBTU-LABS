#include <bits/stdc++.h>
using namespace std;
// vector<pair<int, int> > g2;
vector <vector <int> > g;
vector <int> p;


int dsu(int v){
    if(v == p[v]){
        return v;
    }
    return p[v] = dsu(p[v]);
}

bool dsuUnion(int a, int b){
    a = dsu(a);
    b = dsu(b);
    if(a != b){
        p[a] = b;
        return true;
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i = 0; i < n; i++)p.push_back(i);
    // for (int i = 0; i < g.size(); ++i) {
    //     int u = g[i].first;
    //     int v = g[i].second;
    //     if (dsu(u) != dsu(v)) {
    //         dsuUnion(u, v);
    //     }
    // }

    vector <int> res;
    int cnt = 0;
    // for(int i = 0; i < p.size(); i++)cout << p[i] << ' ';
    // cout << endl;
    for(int i = n - 1; i >= 0; i--){
        res.push_back(cnt);
        cnt++;
        for(int j = 0; j < g[i].size(); j++){
            int to = g[i][j];
            if(i < to){
                if(dsuUnion(i, to)) cnt--;
            }
        }
    }

    for(int i = res.size() - 1; i >= 0; i--){
        cout << res[i] << endl;
    }
    return 0;
}