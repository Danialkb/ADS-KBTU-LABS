#include <bits/stdc++.h>
using namespace std;
vector<int> sieve(int n){
    vector<bool> prime(n + 1, true);
    vector<int> res;
    for(int i = 2; i*i <= n; i++){
        if(prime[i]){
            for(int j = i * i; j <= n; j += i){
                prime[j] = false;
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(prime[i])res.push_back(i);
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<int> s = sieve(n);

    int l = 0, r = s.size() - 1;
    while(l <= r){
        if(s[l] + s[r] == n){
            cout << s[l] << ' ' << s[r];
            break;
        }
        else if((s[l] + s[r]) > n)r--;
        else l++;
    }

    return 0;
}