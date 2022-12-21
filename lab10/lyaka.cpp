#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
map<ull, bool> used;
// map <ull, ull> d;
map<ull, ull> p;

void bfs(int s, int f){
    queue <ull> q;
    q.push(s);
    used[s] = true;
    // d[s] = 0;
    ull cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        // if(cur == f)return;
        if(!used[2 * cur] && cur < f){
            // cout << "ok" << endl;
            q.push(2 * cur);
            used[2 * cur] = true;
            // d[2 * front] = d[front] + 1;
            p[2 * cur] = cur;
            if(2 * cur == f)return;
        }
        if(cur - 1 > 0 && !used[cur - 1]){
            q.push(cur - 1);
            used[cur - 1] = true;
            // d[front - 1] = d[front] + 1;
            p[cur - 1] =  cur;
            if(cur - 1 == f)return;
        }
    }

}


int main(){
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout << 0;
        return 0;
    }
    else if(a > b){
        cout << a - b << endl;
        a -= 1;
        while(a != b){
            cout << a << " ";
            a--;
        }
        cout << b;
        return 0;
    }
    bfs(a, b);
  
    // cout << d[b] << endl;

    vector <ull> res;
    
    while(b != a){
        // cout << "ok";
        res.push_back(b);
        b = p[b];
    }
    cout << res.size() << endl;
    for (int i = res.size() - 1; i >= 0; i--){
        cout << res[i] << " ";
    }
}