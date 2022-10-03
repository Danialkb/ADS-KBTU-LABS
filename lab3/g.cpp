#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
vector<int> v;
bool myHelper(int predict, int h){
    for(int i = 0; i < v.size(); i++){
        if(v[i] % predict == 0)h -= (v[i] / predict);
        else h -= (floor(v[i] / predict) + 1);
        if(h < 0)return false;
    }
    return h >= 0; 
}

int main() {
    int n, h, a, max = -1e9;

    cin >> n >> h;
    for(int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
        if(a > max)max = a;
    }
    int l = 1, r = max + 1, res = -1, mid;
    
    while(l <= r){
        mid = l + (r - l) / 2;
        if(myHelper(mid, h)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << res;

    return 0;
}