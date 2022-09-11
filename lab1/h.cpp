#include <bits/stdc++.h>
using namespace std;
bool isprime(int n){
    if(n == 1)return false;
    if(n == 2)return true;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0)return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    isprime(n) ? cout << "YES" : cout << "NO";
    
    return 0;
}