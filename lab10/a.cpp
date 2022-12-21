#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[1003][1003];
int grib = 0;
queue<pair<int, int> > q;
void eat(int i, int j){
    if(i - 1 >= 0 && arr[i-1][j] == 1){
        grib--;
        arr[i-1][j] = 2;
        arr[i][j] = 0;
        q.push(make_pair(i - 1, j));
    }
    if(i + 1 < n && arr[i + 1][j] == 1){
        grib--;
        arr[i+1][j] = 2;
        arr[i][j] = 0;
        q.push(make_pair(i + 1, j));
    }
    if(j - 1 >= 0 && arr[i][j - 1] == 1){
        grib--;
        arr[i][j - 1] = 2;
        arr[i][j] = 0;
        q.push(make_pair(i, j - 1));
    }
    if(j + 1 < m && arr[i][j + 1] == 1){
        grib--;
        arr[i][j + 1] = 2;
        arr[i][j] = 0;
        q.push(make_pair(i, j + 1));
    }
    
}
int main() {
    cin >> n >> m;
    vector<pair<int, int> > v;
    int res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2)q.push(make_pair(i, j));
            if(arr[i][j] == 1)grib++;
        }
    }

    while(!q.empty()){
        if(grib == 0)break;
        int sz = q.size();
        while(sz--){
            pair<int, int> pos = q.front();
            q.pop();
            eat(pos.first, pos.second);
        }
        res++;
    }

    cout << ((grib != 0) ? -1 : res) << endl;
    return 0;
}