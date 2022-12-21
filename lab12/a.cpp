#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n][n];
    unordered_map<int, bool> m;
    for(int i = 0; i < n; i++) {
        m[i] = true;
        for(int j = 0; j < n; j++)cin >> a[i][j];
    }   

    for(int t = 0; t < n; t++){
        int x;
        cin >> x;
        x--;
        m[x] = false;
        int res = 0;
        for(int i = 0; i < n; i++){
            // if(!m[i]){
                for(int j = 0; j < n; j++){
                    // if(!m[j]){
                        a[i][j] = min(a[i][j], a[i][x] + a[x][j]);
                        // if(!m[i] && !m[j] && a[i][j] > res)res = a[i][j];
                    // }
                }
            // }
        }
        for(int i = 0; i < n; i++){
            if(!m[i]){
                for(int j = 0; j < n; j++){
                    if(!m[j]){
                        res = max(res, a[i][j]);
                    }
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}