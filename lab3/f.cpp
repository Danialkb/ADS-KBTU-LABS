#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, k, a;
    cin >> n;
    vector<int> v;

    while(n--){
        cin >> a;
        v.push_back(a);
    }
    cin >> k;
    sort(v.begin(), v.end());
    while(k--){
        int cnt = 0, sum = 0;
        cin >> a;
        int i = 0;
        while(v[i] <= a){
            cnt++;
            sum += v[i];
            i++;
        }
        cout << cnt << ' ' << sum << endl;
    }

    return 0;
}