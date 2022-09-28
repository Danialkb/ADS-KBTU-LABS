#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int ar[n];
    unsigned long long r;
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
        r += ar[i];
    }

    unsigned long long l = 0, mid;
    while(l <= r){
        mid = l + (r - l) / 2;
        
    }

    return 0;
}