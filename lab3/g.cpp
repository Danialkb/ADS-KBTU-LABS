#include <bits/stdc++.h>
using namespace std;
bool myHelper(vector<long long> &v, long long predict, int h){
    for(int i = 0; i < v.size(); i++){
        if(v[i] % predict == 0)h -= (v[i] / predict);
        else h -= (floor(v[i] / predict) + 1);
    }
    return h >= 0;
}

int main() {
    long long n, h, a, max = INT32_MIN;
    vector<long long> v;
    cin >> n >> h;
    for(int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
        if(a > max)max = a;
    }
    long long l = 0, r = max + 1000, res = 1;
    long long mid;
    while(l + 1 < r){
        mid = (r + l) / 2;
        if(myHelper(v,mid, h)){
            r = mid;
        }
        else l = mid;
    }

    cout << r << endl;

    return 0;
}