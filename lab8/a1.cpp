#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

long long MOD = 1e9 + 7;
long long X = 11;

string hashString(string s) {
    long long hash = 0;
    long long cur = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = ((s[i] - 47) * cur) % MOD;
        hash = (hash + curHash) % MOD;
        cur = (cur * X) % MOD;
    }
    return to_string(hash);
}


int main() {
    int n;
    cin >> n;
    unordered_map<string, bool> m;
    vector<pair<string, string> > v;
    string s;
    for(int i = 0; i < 2 * n; i++){
        cin >> s;
        m[s] = true;
        v.push_back(make_pair(s, hashString(s)));
    }
    int cnt = 0;
    for(int i = 0; i < v.size(); i++){
        if(m[v[i].second]){
            cout << "Hash of string \"" << v[i].first  <<  "\" is " << v[i].second << endl;
            cnt++;
        }
        if(cnt == n)return 0;
    }

    return 0;
}