#include <bits/stdc++.h>
using namespace std;
void Push(string &s, stack<char> &st1){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '#'){
            st1.pop();
        }
        else st1.push(s[i]);
    }
}
int main() {
    string s, t;
    cin >> s >> t;
    stack <char> st1, st2;
    Push(s, st1);
    Push(t, st2);
    if(st1.size() != st2.size()){
        cout << "No\n";
    }
    else{
        while(!st1.empty()){
            if(st1.top() != st2.top()){
                cout << "No\n";
                return 0;
            }
            st1.pop();
            st2.pop();
        }
        cout << "Yes";
    }
    return 0;
}