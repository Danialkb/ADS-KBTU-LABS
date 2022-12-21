#include <bits/stdc++.h>
using namespace std;

// vector<int> merge(vector<int> left, vector<int> right) {
// 	vector<int> result;
// 	int l = 0, r = 0;
// 	while (l < left.size() && r < right.size()) {
// 		if (left[l] <= right[r]) {
// 			result.push_back(left[l]);
// 			l++;
// 		} else {
// 			result.push_back(right[r]);
// 			r++;
// 		}
// 	}
// 	while (l < left.size()) {
// 		result.push_back(left[l]);
// 		l++;
// 	}
// 	while (r < right.size()) {
// 		result.push_back(right[r]);
// 		r++;
// 	}
// 	return result;
// }

// vector<int> merge_sort(vector<int> a, int l, int r) {
// 	if (l == r) {
// 		vector<int> result;
// 		result.push_back(a[l]);
// 		return result;
// 	}
// 	int m = l + (r - l) / 2;
// 	vector<int> left = merge_sort(a, l, m);
// 	vector<int> right = merge_sort(a, m + 1, r);
// 	return merge(left, right);
// }

int partition(vector<int> &a, int left, int right){
    int ind = left;
    int pivot = a[right];
    for(int i = left; i < right; i++){
        if(a[i] < pivot){
            swap(a[i], a[ind]);
            ind++;
        }
    }
    swap(a[ind], a[right]);
    return ind;
}

void quick_sort(vector<int> &a, int left, int right){
    if(left < right){
        int p = partition(a, left, right);
        quick_sort(a, left, p-1);
        quick_sort(a, p+1, right);
    }
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	int x;
	for (int i = 0; i <	 n; i++){
		cin >> x;
		v.push_back(x);
	}
	quick_sort(v, 0, n - 1);
	for(int i = 0; i <	n; i++)cout << v[i] << ' ';
	// int min = 1e9;
	// vector<int> res;
	// for(int i = 0; i < v.size() - 1; i++){
	// 	if(abs(v[i] - v[i+1]) < min){
	// 		res.clear();
	// 		min = abs(v[i] - v[i+1]);
	// 		res.push_back(v[i]);
	// 		res.push_back(v[i+1]);
	// 	}else if(abs(v[i] - v[i+1]) == min){
	// 		res.push_back(v[i]);
	// 		res.push_back(v[i+1]);
	// 	}
	// }

	// for(int i = 0; i < res.size(); i++)cout << res[i] << ' ';
	cout << endl;

	return 0;
}