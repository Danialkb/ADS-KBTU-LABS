#include <bits/stdc++.h>
using namespace std;
bool comparartor(pair<int, int> &p1, pair<int, int> &p2){
    if(p1.second == p2.second)return p1.first > p2.first;
    return p1.second > p2.second;
}
int main() {
    int n, a;
    cin >> n;
    map<int, int> m;
    while(n--){
        cin >> a;
        m[a]++;
    }
    vector<pair<int, int> > v(m.begin(), m.end());
    sort(v.begin(), v.end(), comparartor);
    for(int i = 0; i < v.size(); i++){
        if(v[i].second == v[0].second){
            cout << v[i].first << ' ';
        }
    }
    cout << endl;
    return 0;
}