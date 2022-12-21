#include <bits/stdc++.h>
using namespace std;
int main() {
    set<string> s1;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        string tmp;   
        for(int j = i; j < s.size(); j++) {
            tmp += s[j];
            s1.insert(tmp);
        }
    }

    cout << s1.size() << endl;

    return 0;
}