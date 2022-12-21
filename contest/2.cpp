#include <bits/stdc++.h>
using namespace std;

int check1(string s, int a){
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z')sum += a;
    }
    return sum;
}
int check2(string s, int b){
    int sum = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] >= 'a' && s[i] <= 'z')sum += b;
    }
    return sum;
}
int main() {
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    cout << ((check1(s, k) > check2(s, m)) ? check2(s, m) : check1(s, k)) << endl;

    return 0;
}