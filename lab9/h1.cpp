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
    string s;
    cin >> s;
    vector<int> p = prefixFun(s);
    int cnt = 0;
    for(int i = 1; i < s.size() - 1; i+=2) {
        int sz = i + 1;
        int k = sz - p[i];
        if(p[i] != 0 && sz % k == 0){
            int period = sz / k;
            if(period % 2 == 0)cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}