#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> result;
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (left[l] > right[r]) {
			result.push_back(right[r]);
			r++;
		}
        else{
            result.push_back(left[l]);
            l++;
        }
	}
	while (l < left.size()) {
		result.push_back(left[l]);
		l++;
	}
	while (r < right.size()) {
		result.push_back(right[r]);
		r++;
	}
	return result;
}

vector<int> merge_sort(vector<int> &a) {
	if (a.size() == 1) return a;
    vector<int> al, ar;
    int n = a.size();
    for (int i = 0; i < n / 2; i++) {
        al.push_back(a[i]);
    }
    for (int i = n / 2; i < n; i++) {
        ar.push_back(a[i]);
    }
    al = merge_sort(al);
    ar = merge_sort(ar);
    return merge(al, ar);
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    vector<int> v1(m);
    for(int i = 0; i < n; i++)cin >> v[i];
    for(int i = 0; i < m; i++)cin >> v1[i];
    if(n == 0 || m == 0)return 0;

    v = merge_sort(v);
    v1 = merge_sort(v1);
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