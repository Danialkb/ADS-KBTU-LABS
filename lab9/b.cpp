#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFun(string s) {
    vector<int> pi(s.size());
    pi[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = pi[j - 1];
        }
        if (s[j] == s[i]) {
            pi[i] = j + 1;
        } else {
            pi[i] = 0;
        }
    }

    return pi;
}

int kmp(string s, string t) {
    s = t + '#' + s;
    int res = 0;
    vector<int> pi = prefixFun(s);
    for (int i = 0; i < s.size(); i++) {
        if (pi[i] == t.size())res++;
    }
    return res;
}

int main() {
    string s, t;
    int k;
    cin >> t >> k >> s;
    // cout << kmp(s, t) << endl;
    cout << ((kmp(s, t) >= k) ? "YES\n" : "NO\n");
    return 0;
}