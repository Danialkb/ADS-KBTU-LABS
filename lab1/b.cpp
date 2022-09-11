#include <bits/stdc++.h>
using namespace std;
int foundYoung(stack <int> st, int key){
    int value = -1;
    while(!st.empty()){
        if(st.top() <= key){
            value = st.top();
            break;
        }
        st.pop();
    }
    return value;
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    queue<int> q;
    while(n--){
        int a;
        cin >> a;
        q.push(a);
    }
    vector<int> res;
    res.push_back(-1);
    stack<int> st;
    st.push(q.front());
    q.pop();
    int min = st.top();
    while(!q.empty()){
        if(q.front() >= min)res.push_back(foundYoung(st, q.front()));
        else if(q.front() < min){
            res.push_back(-1);
            min = q.front();
        }
        st.push(q.front());
        q.pop();
    }
    for(int i = 0; i < res.size(); i++){
        cout << res[i] << ' ';
    }
    return 0;
}