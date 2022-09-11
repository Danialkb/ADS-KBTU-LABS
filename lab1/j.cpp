#include <bits/stdc++.h>
using namespace std;
int main() {
    deque<int> dq;
    char c;
    while(cin >> c){
        if(c == '!')break;
        if(c == '+'){
            int a;
            cin >> a;
            dq.push_front(a);
        }
        else if(c == '-'){
            int a;
            cin >> a;
            dq.push_back(a);
        }
        else if(c == '*'){
            if(dq.empty()){
                cout << "error\n";
            }
            else{
                cout << dq.front() + dq.back() << endl;
                dq.pop_back();
                if(!dq.empty())dq.pop_front();
            }
        }
    }

    return 0;
}