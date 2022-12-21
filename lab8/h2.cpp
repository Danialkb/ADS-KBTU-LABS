#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll MOD = 1e9 + 7;
ll X = 31;
vector<ll> mult;

vector<ll> getPrefix(string &s) {
    vector<ll> hashes(s.size());
    ll curX = 1;
    for (int i = 0; i < s.size(); i++) {
        hashes[i] = (s[i] - 96) * curX % MOD; 
        if (i != 0) {
            hashes[i] = (hashes[i] + hashes[i - 1]) % MOD;
        }
        curX = (curX * X) % MOD;
    }
    return hashes;
}

bool rabinKarp(string &s, ll small, vector<ll> &hashes, int &l, int &r) {
    for(int i = 0; i < s.size() - r + 1; i++) {
        ll dif = hashes[i + r - 1];
        if(i!=0)dif -= hashes[i-1];
        if(dif < 0)dif += MOD;

        ll smalltmp = small;
        if(i < l){
            dif = (dif * mult[l - i]) % MOD;
        }
        else smalltmp = (smalltmp * mult[i - l]) % MOD;
        
        if(smalltmp == dif){
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    ll x = 1;
    string minstr = "";
    string s;
    vector<pair<string, vector<ll> > > v;
    int mxsz = 0;
    for(int i = 0; i < n; i++){
        cin >> s;
        v.push_back(make_pair(s, getPrefix(s)));
        if(v[i].first.size() < 5000){
            if(minstr.size() == 0)minstr = v[i].first;
            else {
                if(v[i].first.size() < minstr.size())minstr = v[i].first;
            }
        }
        if(v[i].first.size() > mxsz)mxsz = v[i].first.size();
    }

    mxsz += 5;
    mult.resize(mxsz);
    mult[0] = 1;
    for(int i = 1; i < mxsz; i++){
        mult[i] = (mult[i - 1] * 31 % MOD);
    }

    vector<ll> minHash = getPrefix(minstr);
    string res = "";

    for(int i = 0; i < minstr.size(); i++){
        int l = i, r = minstr.size() - 1, mid;
        while(l <= r){
            mid = l + (r - l)/2;
            ll curh = minHash[mid];
            if(i!=0)curh -= minHash[i - 1];
            if(curh < 0)curh += MOD;
            int bound = mid - i + 1;
            bool flag = true;
            for(int j = 0; j < v.size(); j++){
                if(!rabinKarp(v[j].first, curh, v[j].second, i, bound)){
                    flag = false;
                    break;
                }
            }
            if(flag){
                if(bound > res.size())res = minstr.substr(i, bound);
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
    }
    cout << res << endl;
    return 0;
}