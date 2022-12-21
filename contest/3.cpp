#include <bits/stdc++.h>
using namespace std;
int main() {
    queue<int> q;
    int res = 0, res1 = 0;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        q.push(x);
    }

    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        if(tmp == 1 && q.front() == 0){
            q.front() = 2;
        }
        if(tmp == 0 && q.front() == 0)res++;
        else res1++;
    }
    cout << res << ' ' << res1 << endl;
    return 0;
}