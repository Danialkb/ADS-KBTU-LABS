#include <bits/stdc++.h>
using namespace std;

bool compare(string s, string pivo){
    int year1 = (s[6] - '0') * 1000 + (s[7] - '0') * 100 + (s[8] - '0') * 10 + (s[9] - '0');
    int year2 = (pivo[6] - '0') * 1000 + (pivo[7] - '0') * 100 + (pivo[8] - '0') * 10 + (pivo[9] - '0');
    if(year1 < year2) return true;
    if(year1 > year2)return false;
    int month1 = (s[3] - '0') * 10 + (s[4] - '0');
    int month2 =  (pivo[3] - '0') * 10 + (pivo[4] - '0');
    if(month1 < month2)return true;
    if(month1 > month2)return false;
    return ((s[0] - '0') * 10 + (s[1] - '0')) < ((pivo[0] - '0') * 10 + (pivo[1] - '0'));
}

int partition(vector<string>& a, int l, int r){
    int ind = l;
    string pivot = a[r];
    for(int i = l; i < r; i++){
        if(compare(a[i], pivot)){
            swap(a[i], a[ind]);
            ind++;
        }
    }
    swap(a[ind], a[r]);
    return ind;
}

void quick_sort(vector<string>& a, int l, int r){
    if(l < r){
        int p = partition(a, l, r);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector<string> v;
    while(n--){
        string s;
        cin >> s;
        v.push_back(s);
    }

    quick_sort(v, 0, v.size() - 1);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
    return 0;
}