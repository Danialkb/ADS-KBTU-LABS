#include <bits/stdc++.h>
using namespace std;
class Pasture{
public: 
    int x1, x2, y1, y2;
};

bool check(vector<Pasture> &pastures, int predict, int k, int size){
    int cnt = 0;
    for(int i = 0; i < size; i++){
        if(predict >= pastures[i].x1 && predict >= pastures[i].x2 && predict >= pastures[i].y1 && predict >= pastures[i].y2){
            cnt++;
        }
    }
    return cnt >= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<Pasture> pastures;
    for(int i = 0; i < n; i++){
        Pasture tmp;
        cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
        pastures.push_back(tmp);
    }

    int l = 0, r = 1e9 + 1000, mid, ans = -1;

    while(l <= r){
        mid = l + (r - l) / 2;
        if(check(pastures, mid, k, n)){
            r = mid - 1;
            ans = mid;
        }
        else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}