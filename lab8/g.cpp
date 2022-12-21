#include <iostream>
#include <vector>
using namespace std;

long long MOD = 1e15 + 7;
long long X = 31;
vector<long long> hashes;

long long hashString(string &s, int &l, int &r) {
    long long hash = 0;
    long long cur = 1;
    for (int i = l; i < r + 1; i++) {
        long long curHash = ((s[i] - 96) * cur) % MOD;
        hash = (hash + curHash) % MOD;
        cur = (cur * X) % MOD;
    }
    return hash;
}

void getPrefix(string &s) {
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 'a' + 1) * curX % MOD;
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
}

int rabinKarp(string &s, int &l, int &r) {
    long long small = hashString(s, l, r);
    int res = 0;
    // vector<int> res;
    for (int i = 0; i < s.size() - r + l; i++) {
        long long dif = hashes[i + r - l];
        if (i != 0) {
            dif -= hashes[i - 1];
            if (dif < 0) dif += MOD;
            small = (small * X) % MOD;
        }
        if (small == dif) {
            res++;
        }
    }
    return res;
}


int main() {
    // freopen ("input.txt" , "r", stdin);
    // freopen ("output.txt" , "w", stdout);

    string s;
    cin >> s;
    hashes.resize(s.size());
    getPrefix(s);
    int n;
    cin >> n;
    while(n--){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        // cout << t << endl;
        cout << rabinKarp(s, l, r) << endl;
    }
}