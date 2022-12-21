#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull MOD = 1e15 + 7;
ull X = 31;

int hashString(string &s) {
    int sz = s.size();
    unordered_map<ull, bool> m;
    // map<ull, bool> :: iterator it;
    for (int i = 0; i < sz; i++) {
        ull hash = 0;
        ull cur = 1;
        for(int j = i; j < sz; j++) {
            ull curHash = ((s[j] - 96) * cur) % MOD;
            hash = (hash + curHash) % MOD;
            cur = (cur * X) % MOD;
            if(!m[hash])m[hash] = true;
        }
    }
    
    return m.size();
}

int main() {
    string s;
    cin >> s;
    cout << hashString(s) << endl;

    return 0;
}