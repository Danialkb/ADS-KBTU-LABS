#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> &v){
    int sum = 0;
    for(int i = 0; i < v.size(); i++) sum += v[i];
    return sum;
}

bool comp(vector<int> &v, vector<int> &v1){
    int s1 = sum(v);
    int s2 = sum(v1);
    if(s1 == s2){
        for(int i = 0; i < v1.size(); i++){
            if(v[i] > v1[i])return true;
            else if(v[i] < v1[i])return false;
        }
    }
    return s1 < s2;
}

vector<vector<int> > merge(vector<vector<int> > left, vector<vector<int> > right) {
	vector<vector<int> > result;
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (comp(right[r], left[l])) {
			result.push_back(left[l]);
            l++;
		}
        else{
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

vector<vector<int> > merge_sort(vector<vector<int> > &a) {
	if (a.size() == 1) return a;
    vector<vector<int> > al, ar;
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
    // freopen ("input.txt" , "r", stdin);
    // freopen ("output.txt" , "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > v;
    for(int i = 0; i < n; i++){
        vector<int> tmp(m);
        for(int j = 0; j < m; j++)cin >> tmp[j];
        v.push_back(tmp);
    }

    v = merge_sort(v);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << v[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}