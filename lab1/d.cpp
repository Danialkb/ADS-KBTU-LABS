#include <bits/stdc++.h>
using namespace std;
bool ispal(string &t){
    if(t.size() == 0)return true;
    if(t.size() % 2 == 1)return false;
    int l = 0;
    int r = t.size() - 1;
    while(l <= r){
        if(t[l] != t[r])return false;
        l++;
        r--;
    }
    return true;
}
int main() {
    string s;
    cin >> s;
    string t = s;
    string remaining = "";
    while(1){
        if(ispal(t) && t.size() == s.size()){
            cout << "YES";
            break;
        }
        if(!ispal(t)){
            remaining += t[t.size() - 1];
            t.replace(t.end() - 1, t.end(), "");
            if(ispal(t) && ispal(remaining)){
                cout << "YES";
                break;
            }
        }
        if(t.size() == 0){
            cout << "NO";
            break;
        }
    }

    return 0;
}