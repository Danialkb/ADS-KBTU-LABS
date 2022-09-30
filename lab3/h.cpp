#include <bits/stdc++.h>
using namespace std;
vector<int> p;

int binSearch(int &target){
    int l = 0, r = p.size() - 1;
    while(l <= r){
        int m = l + (r - l) / 2;
        if(p[m] == target){
            return m+1;
        }
        else if (target < p[m] && target > p[m - 1])return m + 1;
        else if(target > p[m])l = m + 1;
        else r = m - 1;
    }
    return 0;
}

int main() {
    // freopen ("input.txt" , "r", stdin);
    // freopen ("output.txt" , "w", stdout);
    int n, m, a;
    cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        p.push_back(sum);
    }

    while(m--){
        cin >> a;
        cout << binSearch(a) << endl;
    }

    return 0;
}