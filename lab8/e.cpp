#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main() {
    int n;
    cin >> n;
    ull x;
    vector<ull> v;
    string res = "";
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
        if(i == 0){
            res += char(x + 97);
        }
        else{
            res += char(((x - v[i - 1]) / pow(2, i)) + 97);
        }
    }

    cout << res << endl;

    return 0;
}