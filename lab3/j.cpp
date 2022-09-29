#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, h, a;
    cin >> n >> h;
   if(newl1 < v[0] && newr1 < v[0] || newl1 > v[v.size() - 1])notfirst = true;
    if(newl2 < v[0] && newr2 < v[0] || newl2 > v[v.size() - 1])notsecond = true;
    if((newl1 == newr1 && newl1 < v[0] && newl2 == newr2 && newl2 < v[0]))continue;
    if(newl2 >= newl1 && newr2 <= newr1) {
        if(!notfirst)cnt = binSearch(r1, "") - binSearch(newl1, "left") + 1;
        cout << binSearch(newl1, "left") << " " << binSearch(newr1, "")<< " " << cnt << endl;
    }
    else if(newl1 >= newl2 && newr1 <= newr2){
        if(!notsecond)cnt = binSearch(newr2, "") - binSearch(newl2, "left") + 1;
        cout << binSearch(newl2, "left") << " " << binSearch(newr2, "")<< " " << cnt << endl;
    }
    else{
        if(!notfirst)cnt += binSearch(newr1, "") - binSearch(newl1, "left") + 1;
        if(!notsecond && newl2 <= newr2)cnt += binSearch(r2, "") - binSearch(newl2, "left") + 1;
        cout << binSearch(newl1, "left") << " " << binSearch(newr1, "") << " "<< binSearch(newl2, "left") << " " << binSearch(newr2, "") << " " << cnt << endl;
    } 
    return 0;
}