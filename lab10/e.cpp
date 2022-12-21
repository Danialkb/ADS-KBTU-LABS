#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen ("input.txt" , "r", stdin);
    // freopen ("output.txt" , "w", stdout);
    int n, q;
    cin >> n >> q;
    int a[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)cin >> a[i][j];
    }

    while(q--){
        int x, y, z;
        cin >> x >> y >> z;
        if(a[x - 1][y - 1] == 1 && a[y - 1][z - 1] == 1 && a[x - 1][z - 1] == 1)cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}