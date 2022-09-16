#include <bits/stdc++.h>
using namespace std;
int MYSIZE = 1000000;
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    // vector<int> res;
    vector<bool> primes(MYSIZE, true);
    for(int i = 2; i < MYSIZE; i++){
        if(primes[i]){
            cnt++;
            if(cnt == n){
                cout << i;
                return 0;
            }
            for(int j = i * i; j < MYSIZE; j += i){
                primes[j] = false;
            }
        }
    }
    return 0;
}