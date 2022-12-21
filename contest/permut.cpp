#include <bits/stdc++.h>
using namespace std;


void print(vector<int> v){
    for(int i = 0; i < v.size(); i++)cout << v[i] << ' ';
    cout << endl;
}

int main() {
    // freopen ("input.txt" , "r", stdin);
    // freopen ("output.txt" , "w", stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v;
        for(int i = 0; i < v.size(); i++){
            int x;
            cin >> x;
            v.push_back(x);
        }

        for(int i = 0;i < v.size();i++){
            int cur = v[i];
            int pos = i;
            for(int j = i + 1; j < v.size(); j++){
                if(cur > v[j]){
                    cur = v[j];
                    pos = j;
                }
            }
            for(int j = pos; j > i; j--){
                swap(v[j],v[j-1]);
            }
            if(pos != i)i = pos - 1;
        }
        print(v);
    }

    return 0;
}