#include <bits/stdc++.h>
using namespace std;

bool check(int n){
    vector<int> v;
    while(n > 0){
        v.push_back(n % 10);
        n /= 10;
    }
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            if(v[i] == v[j])return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while(1){
        n++;
        if(check(n)){
            cout << n << endl;
            break;
        }
    }

    return 0;
}