#include <bits/stdc++.h>
using namespace std;

int partition(int a[], int l, int r){
    int pivot = a[r];
    int ind = l;
    for(int i = l; i < r; i++){
        if(a[i] > pivot){
            swap(a[i], a[ind]);
            ind++;
        }
    }
    swap(a[ind], a[r]);
    return ind;
}

void quick_sort(int a[], int left, int right){
    if(left < right){
        int p = partition(a, left, right);
        quick_sort(a, left, p - 1);
        quick_sort(a, p + 1, right);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int ar[m][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> ar[j][i];
        }
    }

    for(int i = 0; i < m; i++)quick_sort(ar[i], 0,  n - 1);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ar[j][i] << ' ';
        }
        cout << endl;
    }



    return 0;
}