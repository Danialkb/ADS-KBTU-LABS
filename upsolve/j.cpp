#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> m >> n;

    vector<int> v(n);
    vector<int> res;
    for(int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());

    int l = 0, r = n - 1;
    while(l < r){
        if(v[l] + v[r] == 0){
            cout << v[l] << ' ' << v[r] << endl;
            break;
        }
        
    }


    // for(int i = 0; i < n; i++){
    //     int tmp = m - v[i];
    //     int l = 0, r = v.size() - 1, mid;
    //     if(tmp < 0)continue;
    //     while(l <= r){
    //         mid = l + (r - l) / 2;
    //         if(v[mid] == tmp){
    //             cout << v[i] << ' ' << v[mid] << endl; 
    //             return 0;
    //         }
    //         else if(v[mid] > tmp){
    //             r = mid - 1;
    //         } else l = mid + 1;
    //     }
    // }

    return 0;
}