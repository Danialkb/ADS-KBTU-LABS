#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v;
    int mn = 1e9, ind = -1;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
        if(x < mn){
            mn = x;
            ind = i;
        }
    }

    int sum = 0;
    
    for(int i = 0; i < n; i++){
        if(i != ind)sum += v[i] + mn;
    }

    cout << sum << endl;

    return 0;
}