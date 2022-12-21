#include <bits/stdc++.h>
using namespace std;

int help(vector<pair<int, int> > &v, pair<int, int> predict, int n){
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i].first != predict.first && v[i].second != predict.first 
        && v[i].first != predict.second && v[i].second != predict.second)cnt+=2;
    }
    return cnt;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int> > v;

    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }



    int l = 1, r = n, ans = 1;

    while(l <= r){
        int mid = l + (r - l) / 2;
        int count = help(v, v[mid], n);
        if(count <= n){
            ans = count;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << endl;
    // for(int i = 0; i < )
    return 0;
}