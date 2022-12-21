#include <bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right) {
	vector<int> result;
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (left[l] <= right[r]) {
			result.push_back(left[l]);
			l++;
		} else {
			result.push_back(right[r]);
			r++;
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

int main() {
    int n, m;
    cin >> n;
    vector<int> l(n);
    for(int i = 0; i < n; i++)cin >> l[i];
    cin >> m;
    vector<int> r(m);
    for(int i = 0; i < m; i++)cin >> r[i];
    l = merge(l, r);
    for(int i = 0; i < l.size(); i++){
        cout << l[i] << ' ';
    }
    return 0;
}