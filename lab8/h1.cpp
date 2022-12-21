#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e15 + 7;
long long X = 31;

long long hashString(string &s) {
    long long hash = 0;
    long long cur = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = ((s[i] - 96) * cur) % MOD;
        hash = (hash + curHash) % MOD;
        cur = (cur * X) % MOD;
    }
    return hash;
}

vector<long long> getPrefix(string &s) {
    vector<long long> hashes(s.size());
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
}

bool rabinKarp(string &s, string &t, vector<long long> &hashes) {
    long long small = hashString(t);
    int res = 0;
    
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        long long dif = hashes[i + t.size() - 1];
        if (i != 0) {
            dif -= hashes[i - 1];
            if (dif < 0) dif += MOD;
            small = (small * X) % MOD;
        }
        if (small == dif)return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    string s;
    string minstr = "";
    vector<pair<string, vector<long long> > > v;
    while(n--){
        cin >> s;
        v.push_back(make_pair(s, getPrefix(s)));
        if(s.size() > minstr.size() && minstr.size() == 0){
            minstr = s;
        }
        else if(s.size() < minstr.size())minstr = s;
    }

    // string res = "";
    // cout << minstr << endl;
    string ans = "";
    for(int i = 0; i < minstr.size(); i++){
        int fast = (minstr.size() - i);
        string cur = "";
        for(int j = i; j < minstr.size(); j++){
            cur += minstr[j];
            // cout << res << endl;
            bool flag = true;
            for(int k = 0; k < v.size(); k++){
                if(!rabinKarp(v[k].first, cur, v[k].second)){
                    flag = false;
                    break;
                }
            }
            if(flag && cur.size() > ans.size()){
                ans = cur;
                // cout << res << endl;
                // return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}