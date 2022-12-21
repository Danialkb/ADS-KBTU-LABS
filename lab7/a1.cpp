#include <bits/stdc++.h>
using namespace std;

vector<string> merge(vector<string> left, vector<string> right) {
	vector<string> result;
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (left[l].size() > right[r].size()) {
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

vector<string> merge_sort(vector<string> &a) {
	if (a.size() == 1) return a;
    vector<string> al, ar;
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
    string tmp;
    getline(cin, tmp);
    int n = stoi(tmp);
    vector<vector<string> > res;
    for(int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        s += ' ';
        vector<string> tmp;
        string pih = "";
        for(int pos = 0; pos < s.size(); pos++){
            if(s[pos] == ' '){
                tmp.push_back(pih);
                pih = "";
            }else pih += s[pos];
        }
        tmp = merge_sort(tmp);
        res.push_back(tmp);
    }

    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}