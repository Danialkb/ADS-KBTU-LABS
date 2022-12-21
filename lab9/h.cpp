#include <bits/stdc++.h>
using namespace std;
vector<int> z_fun(string s) {
    vector<int> z(s.size());
    for (int i = 1, l = 0, r = 0; i < s.size(); i++) {
        if (i <= r) z[i] = min(z[i - l], r - i + 1);
        while (i + z[i] < s.size()) {
            if (s[i + z[i]] == s[z[i]]) z[i]++;
            else break;
        }
        if (z[i] > 0 && i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
int main() {
    string s;
    cin >> s;
    vector<int> v = z_fun(s);

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }

    return 0;
}