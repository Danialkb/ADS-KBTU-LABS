#include <bits/stdc++.h>
using namespace std;
string predictVictory(string s) {
        int n = s.size();
        queue<int> sak, kat;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'S') {
                sak.push(i);
            } else {
                kat.push(i);
            }
        }
        while (!sak.empty() && !kat.empty()) {
            if (sak.front() < kat.front()) {
                sak.push(sak.front() + n);
            } else {
                kat.push(kat.front() + n);
            }
            sak.pop();
            kat.pop();
        }
        return !sak.empty() ? "SAKAYANAGI" : "KATSURAGI";
    }
int main() {
    int n;
    string s;
    cin >> n >> s;
    cout << predictVictory(s);

    return 0;
}