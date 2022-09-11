#include <bits/stdc++.h>
using namespace std;
int main() {
    stack<int> res;
    vector<int> v;
    int n;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        v.push_back(a);
    }
    for(int i = v.size() - 1; i >= 0; i--){
        bool founded = false;
        for(int j = i - 1; j >= 0; j--){
            if(v[j] <= v[i]){
                res.push(v[j]);
                founded = true;
                break;
            }
        }
        if(!founded)res.push(-1);
    }
    while(!res.empty()){
        cout << res.top() << ' ';
        res.pop();
    }
    return 0;
}