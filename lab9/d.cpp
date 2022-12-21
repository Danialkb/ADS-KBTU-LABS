#include <bits/stdc++.h>
#include <cctype>
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

bool kmp(string s, string t) {
    s = t + '#' + s;
    vector<int> res;
    vector<int> pi = prefixFun(s);
    for (int i = 0; i < s.size(); i++) {
        if (pi[i] == t.size())return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> v;
    while(n--){
        string t;
        cin >> t;
        v.push_back(t);
    }
    vector<string> res;
    for(int i = 0; i < s.size(); i++){
        string tmp = "";
        tmp += toupper(s[i]);
        for(int j = i + 1; j < s.size(); j++ ){
            tmp += s[j];
        }
        for(int k = 0; k < v.size(); k++){
            if(kmp(v[k], tmp))res.push_back(v[k]);
        }
        if(res.size() != 0)break;
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << endl;
    }

    return 0;
}