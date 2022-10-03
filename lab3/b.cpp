#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
vector<int> v;

bool check(ull predict, int k){
    ull cnt = 1, sum = 0;

    for(int i = 0; i < v.size(); i++){
        if(v[i] > predict)return false;
        if(sum + v[i] > predict){
            cnt++;
            sum = v[i];
        }
        else sum += v[i];
    }

    return cnt <= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    ull l = 0, r = 0, ans, mid;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        if(x > l)l = x;
        r += x;
    }

    while(l <= r){
        mid = l + (r - l)/2;
        if(check(mid, k)){
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    cout << ans << endl;

    return 0;
}