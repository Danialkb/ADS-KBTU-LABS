#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s){
    int n = (int)s.length();
    vector<int> pi(n);
    for(int i = 1; i < n; i++){
        int j = pi[i-1];
        while(j > 0 and s[i] != s[j]){
            j = pi[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}


int main(){
    string s;
    int t;
    cin >> s >> t;
    vector<string>vec;
    for(int i = 0; i < t; i++){
        string st;
        cin >> st;
        vec.push_back(st);
    }
    vector<pair<string,int> >  ans;
    for(int i = 0; i < vec.size(); i++){
        string name = vec[i];
        name[0] +=32;
        vector<int> a = prefix_function(name + '#' + s);
        ans.push_back(make_pair(name,a[a.size() - 1]));
    }
    int mx = -1;
    for(int i = 0; i < ans.size(); i++){
        // cout << ans[i].first << " " << ans[i].second;
        if(mx < ans[i].second){
            mx = ans[i].second;
        }
    }
    vector<string> vc;
    for(int i = 0; i < ans.size(); i++){
        // cout << ans[i].first << " " << ans[i].second;
        if(mx == ans[i].second){
            string kala = ans[i].first;
            kala[0] -= 32;
            vc.push_back(kala);
        }
    }
    if(mx == 0){
        cout << 0;
        return 0;
    }
    cout << vc.size() << endl;
    for(int i = 0; i <vc.size(); i++){
        cout << vc[i]<< endl;
    }
}