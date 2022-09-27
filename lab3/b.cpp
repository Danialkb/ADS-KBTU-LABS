#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, a;
    cin >> n >> k;
    vector<int> v;
    int sum = 0;

    for(int i = 0; i < n; i++) {
        cin >>a;
        sum += a;
        v.push_back(a);
    }

    int l = 1;
    int r = sum;

    while(l <= r) {
        int mid = (l + r) / 2;

    }


    return 0;
}