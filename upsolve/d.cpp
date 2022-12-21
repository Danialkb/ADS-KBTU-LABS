#include <bits/stdc++.h>
using namespace std;

int sieve(int n){
    if(n < 2)return 0;
    // n = sqrt(n);
    vector<bool> prime(n + 1, true);
    int res = 0;
    long long mult = 1;
    int k = n;
    for(int i = 2; i*i <= k; i++){
        if(prime[i]){
            for(int j = i * i; j <= k; j += i){
                prime[j] = false;
            }
            // if(n%i == 0)
            // cout << i << endl;
            if(n%i == 0){
                // cout << i << endl;
                mult *= i;
            }
            if(mult > n)return res;
            if(k%i == 0)res++;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << sieve(n) << endl;
    return 0;
}