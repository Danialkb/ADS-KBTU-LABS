#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

long long MOD = 1e9 + 7;
long long X = 31;
vector<long long> mult;
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
    int k;
    cin >> k;
    mult.resize(5005);
    mult[0] = 1;
    for(int i = 1; i < 5000; i++){
        mult[i] = mult[i - 1] * 
    }
    unordered_map<pair<string, long long>, int> m;
    string ans = "";
    for(int i = 0; i < k; i++){
        unordered_set<long long> s;
        string t;
        cin >> t;
        for(int j = 0; j < t.size(); j++){
            string tmp = "";
            for(int k = j; k < t.size(); k++){
                tmp += t[k];
                s.insert(hashString(tmp));
            }
        }

        unordered_set<long long>:: iterator it;

        for(it = s.begin(); it != s.end(); it++){
            // cout << *it << endl;
            m[*it]++;
        }
    }


    unordered_map<pair<string, long long>, int> :: iterator it1;

    for(it1 = m.begin(); it1 != m.end(); it1++){
        if(it1->second == k){
            if(it1->first.first.size() > ans.size()){
                ans = it1->first.first;
            }
        }
    }

    cout << ans << endl;

    return 0;
}