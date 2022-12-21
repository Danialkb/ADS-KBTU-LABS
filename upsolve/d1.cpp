#include <bits/stdc++.h>
using namespace std;

// vector<int> sieve(long long n){
//     vector<bool> prime(n + 1, true);
//     vector<int> res;
//     for(int i = 2; i*i <= n; i++){
//         if(prime[i]){
//             for(int j = i * i; j <= n; j += i){
//                 prime[j] = false;
//             }
//         }
//     }
//     for(int i = 2; i <= n; i++){
//         if(prime[i])res.push_back(i);
//     }
//     return res;
// }
int sieve(long long n){
    if(n < 2)return 0;
    if(n == 2)return 1;
    vector<bool> prime(n + 1, true);
    int res = 0;
    int k = n;
    for(int i = 2; i <= k; i++){
        if(prime[i]){
            for(int j = i * i; j <= k; j += i){
                prime[j] = false;
            }
            int k = 0;
            while(n%i == 0){
                if(k == 0)res++;
                n/=i;
                k++;
            }
            if(n == 1)return res;
        }
    }
    return res;
}

// bool isprime(long long n){
//     if(n == 0 || n == 1)return false;
//     if(n == 2)return true;
//     for(int i = 2; i * i <= n; i++){
//         if(n % i == 0)return false;
//     }
//     return true;
// }

void primeFactors(int n){
    set<int> s;
    int div = 2;
    while(n>1)
    {
        if(n%div == 0){
            s.insert(div);
            n/=div;
        }
        else div++;
    }
    cout << s.size() << endl;
}

int main() {
    long long n;
    cin >> n;
    primeFactors(n);
    // cout << sieve(n) << endl;
    // vector<int> p = sieve(n);    
    // primeFactors(n, p);
    // if(isprime(n)){
    //     cout << 1 << endl;
    //     return 0;
    // }
    // int cnt = 0;
    // for(int i = 0; i < p.size(); i++){
    //     if(n % p[i] == 0){
    //         cnt++;
    //         if(isprime(n/p[i]) 
    //         && (p[i] != int(n/p[i])))cnt++;
    //     }
    // }
    // cout << cnt << endl;
    return 0;
}