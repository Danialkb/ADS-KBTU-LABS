#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<int> color;
int num = 0;
vector<int> ord;
stack<int> st;
bool cycle(int v, int s, int end){
    color[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        if(v == s && g[v][i] == end)continue;
        if(color[g[v][i]] == 1)return true;
        if(color[g[v][i]] == 0 && cycle(g[v][i], s, end))return true;
    }
    color[v] = 2;
    return false;
}

bool cycle2(int v){
    color[v] = 1;
    st.push(v);
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if(color[to] == 1){
            while(st.top() != to){
                ord.push_back(st.top());
                st.pop();
            }
            ord.push_back(to);
            ord.push_back(v);
            reverse(ord.begin(), ord.end());
            return true;
        }
        if(color[to] == 0 && cycle2(to))return true;
    }
    color[v] = 2;
    if(!st.empty())st.pop();
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    color.resize(n);
    g.resize(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(cycle2(i)){
            flag = true;
            break;
        }
    }
    // for(int i = 0; i < ord.size(); i++){
    //     cout << ord[i] + 1 << " ";
    // }
    if(!flag){
        cout << "YES\n";
    }else{
        // flag = false;
        for(int i = 0; i < ord.size() - 1; i++){
            bool cur = false;
            for(int j = 0; j < n; j++){
                color.assign(n, 0);
                if(color[i] == 0)cur |= cycle(j, ord[i], ord[i + 1]);
            }
            if(!cur){
                cout << "YES\n";
                return 0;
            }
        }
        cout << "NO\n";
    }


    return 0;
}