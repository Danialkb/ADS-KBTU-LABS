#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
vector <bool> used(5005);
map <int, int> d;
vector <int> p(5005);

void bfs(int s, int f){
    queue <ull> q;
    q.push(s);
    used[s] = true;
    d[s] = 0;

    while(!q.empty()){
        int front = q.front();
        q.pop();

        if (2 * front == f) {
            d[2 * front] = d[front] + 1;
            p[2 * front] = front;
            break;
        }

        else if (front - 1 == f) {
            d[front - 1] = d[front] + 1;
            p[front - 1] = front;
            break;
        }
        
        if(!used[2 * front]){
            q.push(2 * front);
            used[2 * front] = true;
            d[2 * front] = d[front] + 1;
            p[2 * front] = front;
      
        }
        if(!used[front - 1] && front != 0){
            q.push(front - 1);
            used[front - 1] = true;
            d[front - 1] = d[front] + 1;
            p[front - 1] =  front;
        
        }
    }

}




int main(){
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout << 0;
        return 0;
    }
    else if(a > b){
        cout << a - b << endl;
        a -= 1;
        while(a != b){
            cout << a << " ";
            a--;
        }
        cout << b;
        return 0;
    }
    bfs(a, b);
  
    cout << d[b] << endl;

    vector <ull> res;
    
    while(b != a){
        // cout << "ok";
        res.push_back(b);
        b = p[b];
    }

    for (int i = res.size() - 1; i >= 0; i--){
        cout << res[i] << " ";
    }
    
    
   

}