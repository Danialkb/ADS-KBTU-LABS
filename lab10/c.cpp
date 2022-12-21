#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
map<ull, bool> vis;
map<ull, ull> pre;
void bfs(ull s, ull b){
    queue<ull> q;
    q.push(s);
    while(!q.empty()){
        ull a = q.front();
        q.pop();
        ull res1 = 2 * a, res2 = a - 1;
        if(!vis[2 * a] && a < b){
            q.push(res1);
            vis[res1] = true;
            pre[res1] = a;
            if(res1 == b)break;
        }
        if(!vis[res2]){
            q.push(res2);
            vis[res2] = true;
            pre[res2] = a;
            if(res2 == b)break;
        }
    }
}
int main() {
    ull a, b;
    cin >> a >> b;
    if(a == b){
        cout << 0 << endl;
        return 0;
    }
    bfs(a, b);
    vector<int> res;
    while(b != a){
        res.push_back(b);
        b = pre[b];
    }
    cout << res.size() << endl;
    for(int i = res.size() - 1; i >= 0; i--)cout << res[i] << ' ';
    return 0;
}