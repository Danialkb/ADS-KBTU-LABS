#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<string> v;
    while(n--){
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        a -= x;
        b -= y;
        while(c != 0 && a < 0){
            a++;
            c--;
        }
        while(b < 0 && c != 0){
            b++;
            c--;
        }
        if(b < 0 || a < 0)v.push_back("NO");
        else v.push_back("YES");
    }

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}