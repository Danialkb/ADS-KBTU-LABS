#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<char> c(n);

    for (int i = 0; i < n; i++)cin >> c[i];
    char target;
    cin >> target;
    int l = 0, r = n - 1, mid;
    char ans = c[0];
    while(l <= r){
        mid = l + (r - l) / 2;
        if(c[mid] > target){
            ans = c[mid];
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << endl;
    return 0;
}