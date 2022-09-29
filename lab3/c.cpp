#include <bits/stdc++.h>
using namespace std;
vector<int> v;

int binSearch(int &target, string s){
    int left = 0;
    int right = v.size() - 1;
    while(left <= right){
        int mid = (left + right) / 2;
        if(v[mid] == target){
            return mid;
        }
        if(target < v[0])return 0;
        if(target > v[v.size() - 1])return v.size() - 1;
        if(v[mid] == target)
            return mid;
        if(target > v[mid] && target < v[mid + 1]){
            if(s == "left")return mid + 1;
            else return mid;
        }
        if(target > v[mid])left = mid + 1;
        else if (target < v[mid])right = mid - 1;
    }
    return 0;
}

int main() {
    // freopen ("input.txt" , "r", stdin);
    // freopen ("output.txt" , "w", stdout);
    int n, k, a;
    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    // for(int i = 0; i < v.size(); i++)cout << v[i] << ' ';
    // cout << endl;
    for(int i = 0; i < k; i++) {
        int l1, r1, l2, r2;

        cin >> l1 >> r1 >> l2 >> r2;
        int cnt = 0;

        int newl1 = min(l1, l2);
        int newl2 = max(l2, l1);
        int newr1 = min(r1, r2);
        int newr2 = max(r2, r1);

        if(newl2 >= newl1 && newr2 <= newr1) {
            if((newr1 >= v[0] || newl1 >= v[0]) && (newl1 <= v[v.size() - 1]))cnt = binSearch(r1, "") - binSearch(newl1, "left") + 1;
            // cout << binSearch(newl1, "left") << " " << binSearch(newr1, "")<< " " << cnt << endl;
        }
        else if(newl1 >= newl2 && newr1 <= newr2){
            if((newr2 >= v[0] || newl2 >= v[0]) && (newl2 <= v[v.size() - 1]))cnt = binSearch(newr2, "") - binSearch(newl2, "left") + 1;
            // cout << binSearch(newl2, "left") << " " << binSearch(newr2, "")<< " " << cnt << endl;
        }
        else{
            if(newl2 < newr1)newl2 = newr1+1;
            if((newr1 >= v[0] || newl1 >= v[0]) && (newl1 <= v[v.size() - 1]))cnt += binSearch(newr1, "") - binSearch(newl1, "left") + 1;
            
            if((newr2 >= v[0] || newl2 >= v[0]) && (newl2 <= v[v.size() - 1]))cnt += binSearch(newr2, "") - binSearch(newl2, "left") + 1;
        }
    
        
        cout << cnt << endl;
    }

    return 0;
}