#include <iostream>
#include <vector>
using namespace std;



long long MOD = 1e9 + 7;
long long X = 31;

long long hashString(string s) {
    long long hash = 0;
    long long cur = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = ((s[i] - 96) * cur) % MOD;
        hash = (hash + curHash) % MOD;
        cur = (cur * X) % MOD;
    }
    return hash;
}

vector<long long> getPrefix(string s) {
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

vector<int> rabinKarp(string s, string t) {
    long long small = hashString(t);
    vector<int> res;
    vector<long long> hashes = getPrefix(s);
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        long long dif = hashes[i + t.size() - 1];
        if (i != 0) {
            dif -= hashes[i - 1];
            if (dif < 0) dif += MOD;
            small = (small * X) % MOD;
        }
        if (small == dif) {
            res.push_back(i);
        }
    }
    return res;
}

int main() {
    string s, t;
    cin >> s >> t;
    string pattern;
    cin >> pattern;
    vector<int> v1 = rabinKarp(s, pattern);
    vector<int> v2 = rabinKarp(t, pattern);
    int cnt = 0;
    int l = 0;
    int r = 0;
    while(l < v1.size() && r < v2.size()) {
        if(v1[l] == v2[r])cnt++;
        if(v1[l] < v2[r])l++;
        else r++;
    }
    cout << cnt << endl;
    // cout << endl;
    return 0;
}