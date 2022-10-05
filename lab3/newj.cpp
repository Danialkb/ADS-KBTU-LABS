#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int check(int predict, int h){
    for(int i = 0; i < v.size(); i++){
        if(v[i] % predict == 0)h -= (v[i] / predict);
        else h -= (floor(v[i] / predict) + 1);
    }
    return h;
}

int main() {
    int n, h, max = -1e9;
    cin >> n >> h;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
        if(x > max)max = x;
    }
    // cout << check(4, h);
    int l = 1, r = max;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(check(mid, h) == 0 && check(mid - 1, h) != 0){
            cout << mid;
            break;
        }
        else if((check(mid,h) > 0) && (check(mid - 1, h) < 0)){
            cout << mid << endl;
            break;
        }
        else if(check(mid,h) < 0)l = mid + 1;
        else r = mid - 1;
    }


    return 0;
}