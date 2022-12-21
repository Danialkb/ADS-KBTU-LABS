#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    vector<int> ans;
    while(t--) {
        int x, y;
        cin >> x >> y;
        if(x < y){
            ans.push_back(y - x);
        }
        else if(x == y){
            ans.push_back(0);
        }
        else if(x % y == 0){
            ans.push_back(x - y);
        }
        else{
            int tmp = y;
            int cnt = 1;
            while(1){
                if(tmp * cnt >= x){
                    ans.push_back(tmp * cnt  - x);
                    break;
                }else cnt++;
            }
        }   
    }

    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}