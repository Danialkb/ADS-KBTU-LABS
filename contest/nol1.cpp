#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    int max = -1e9;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > max)max = a[i];
    }

    int cnt[max];
    for(int i = 0; i < max; i++)cnt[i] = 0;

    for(int i = 0; i < n; i++){
        cnt[a[i] - 1]++;
    }

    for(int i = 0; i < max; i++){
        if(cnt[i] != 0 && cnt[i] % 2 != 0){
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";

    return 0;
}