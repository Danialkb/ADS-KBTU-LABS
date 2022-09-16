#include <bits/stdc++.h>
using namespace std;
int main() {
    queue<int> q;
    vector<int> res;
    int n, a;
    cin >> n;
    while(n--){
        cin >> a;
        q.push(a);
    }
    stack<int> st;
    while(!q.empty()){
        stack<int> deleted;
        int nearest = -1;
        while(!st.empty()){
            if(st.top() <= q.front()){
                nearest = st.top();
                break;
            }
            deleted.push(st.top());
            st.pop();
        }
        while(!deleted.empty()){
            st.push(deleted.top());
            deleted.pop();
        }
        st.push(q.front());
        q.pop();
        res.push_back(nearest);
    }
    for(int i = 0; i < res.size(); i++)cout << res[i] << ' ';
    return 0;
}