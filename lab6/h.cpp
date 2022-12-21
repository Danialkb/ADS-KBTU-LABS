#include <bits/stdc++.h>
using namespace std;
char pivo;

void quick_sort(vector<char> &a, int l, int r) {
    if (r < l + 1) return;
    int mid = (l + r) / 2;
    char pivot = a[mid];
    int j = l;
    swap(a[r], a[mid]);
    for (int i = l; i <= r; i++) {
        if (a[i] < pivot){
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[j], a[r]);
    quick_sort(a, l, j -1);
    quick_sort(a, j+1, r);
}

int main() {
    int n;
    cin >> n;
    vector<char> c(n);

    for (int i = 0; i < n; i++)cin >> c[i];
    cin >> pivo;
    vector<char> v;
    for(int i = 0; i < n; i++){
        if(c[i] > pivo)v.push_back(c[i]);
    }
    if(v.size() == 0){
        cout << c[0] << endl;
        return 0;
    }
    quick_sort(v, 0, v.size() - 1);
    cout << v[0] << endl;
    return 0;
}