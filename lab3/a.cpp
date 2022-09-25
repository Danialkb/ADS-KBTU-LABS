#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > v;
vector<vector<int> > res;
void binSearch(int &target){
    for(int i = 0; i < v.size(); i++){
        int l = 0;
        int r = v[i].size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(v[i][mid] == target){
                res.push_back({i, mid});
                return;
            }
            if(i % 2 == 0){
                if(v[i][mid] > target){
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            else{
                if(v[i][mid] > target){
                    r = mid - 1;
                }
                else l = mid + 1;
            }
        }
    }
    res.push_back({-1});
}


int main() {
    int k, n, m, a;
    cin >> k;
    vector<int> t;
    
    while(k--){
        cin >> a;
        t.push_back(a);
    }

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        vector<int> tmp;
        for(int j = 0; j < m; j++){
            cin >> a;
            tmp.push_back(a);
        }
        v.push_back(tmp);
    }

    for(int i = 0; i < t.size(); i++){
        binSearch(t[i]);
    }

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}