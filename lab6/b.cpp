#include <bits/stdc++.h>
using namespace std;

void quick_sort(vector<int> &a, int l, int r) {
    if (r < l + 1) return;
    int mid = (l + r) / 2;
    int pivot = a[mid];
    int j = l;
    swap(a[r], a[mid]);
    for (int i = l; i <= r; i++) {
        if (a[i] < pivot){
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[j], a[r]);
    quick_sort(a, l, j - 1);
    quick_sort(a, j + 1, r);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> v1(m);
    for(int i = 0; i < n; i++)cin >> v[i];
    for(int i = 0; i < m; i++)cin >> v1[i];
    if(n == 0 || m == 0)return 0;

    quick_sort(v, 0, n - 1);
    quick_sort(v1, 0, m - 1);

    int l1 = 0, l2 = 0;
    while(l1 < n && l2 < m){
        if(v[l1] == v1[l2]){
            cout << v[l1] << ' ';
            l1++;
            l2++;
        }
        else if(v[l1] < v1[l2])l1++;
        else l2++;
    }

    return 0;
}