#include <bits/stdc++.h>
using namespace std;

bool isprime(int &num){
    if(num == 0 || num == 1)return false;
    if(num == 2)return true;
    for(int i = 2; i * i <= num; i++){
        if(num % i == 0)return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    int num = 1, cnt = 0, pos = 0;
    while(1){
        num++;
        if(isprime(num)){
            pos++;
            if(isprime(pos))cnt++;
        }
        if(cnt == n){
            cout << num;
            return 0;
        }
    }


    return 0;
}