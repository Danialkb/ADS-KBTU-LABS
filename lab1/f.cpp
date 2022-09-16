#include <bits/stdc++.h>
using namespace std;
bool isprime(int &num){
    if(num == 2)return true;
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0)return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    int num = 1, cnt = 0;
    while(1){
        num++;
        if(isprime(num))cnt++;
        if(cnt == n){
            cout << num;
            return 0;
        }
    }
    return 0;
}