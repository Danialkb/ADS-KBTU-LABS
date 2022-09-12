#include <bits/stdc++.h>
using namespace std;
void print(deque<int> dq){
    while(!dq.empty()){
        cout << dq.front() << ' ';
        dq.pop_front();
    }
    cout << endl;
}
void Cards(int a, deque<int> &dq){
    while(a > 0){
        dq.push_front(a);
        if(dq.size() > 1){
            for(int i = 0; i < a; i++){
                int tmp = dq.back();
                dq.pop_back();
                dq.push_front(tmp);
            }
        }
        a--;
    }
    print(dq);
}
int main() {
    int n;
    cin >> n;
    while(n--){
        deque<int> dq;  
        int a;
        cin >> a;
        Cards(a, dq);
    }
    return 0;
}