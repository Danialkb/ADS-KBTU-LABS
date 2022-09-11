#include <bits/stdc++.h>
using namespace std;
void input(queue<int> &q){
    for(int i = 0; i < 5; i++){
        int a;
        cin >> a;
        if(a == 0)q.push(0);
        else q.push(a);
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    queue<int> q1, q2;
    input(q1);
    input(q2);
    int cnt = 0;
    while(1){
        if(cnt >= pow(10, 6)){
            cout << "blin nichya";
            break;
        }
        else if(q1.empty()){
            cout << "Nursik " << cnt; 
            break;
        }
        else if(q2.empty()){
            cout << "Boris " << cnt; 
            break;
        }
        else if(q1.front() >= q2.front()){
            if(q1.front() == 9 && q2.front() == 0){
                int tmp = q2.front();
            q2.pop();
            q2.push(q1.front());
            q2.push(tmp);
            q1.pop();
            }
            else{
                int tmp = q1.front();
                q1.pop();
                q1.push(tmp);
                q1.push(q2.front());
                q2.pop();
            }
        }
        else if(!q2.empty() && q1.front() < q2.front()){
            if(q1.front() == 0 && q2.front() == 9){
                int tmp = q1.front();
                q1.pop();
                q1.push(tmp);
                q1.push(q2.front());
                q2.pop();
            }
            else{
                int tmp = q2.front();
                q2.pop();
                q2.push(q1.front());
                q2.push(tmp);
                q1.pop();
            }
        }
        cnt++;
    }
    return 0;
}