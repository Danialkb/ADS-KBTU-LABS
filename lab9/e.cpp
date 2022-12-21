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

int main() {
    // freopen ("input.txt" , "r", stdin);
    // freopen ("output.txt" , "w", stdout);
    int n;
    cin >> n;
    while(n--){
        string s;
        int k;
        cin >> s >> k;
        vector<int> v = prefixFun(s);
        cout << (k - 1) * (s.size() - v[v.size() - 1]) + s.size() << endl;
    }
    return 0;
}