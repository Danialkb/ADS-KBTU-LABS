#include <bits/stdc++.h>
using namespace std;
vector<string> merge(vector<string> v1, vector<string> v2, vector<string> v3) {
	vector<string> result;
	int l = 0, r = 0, k = 0;
	while (l < v1.size() && r < v2.size() && k < v3.size()) {
		if (v1[l] < v2[r] && v1[r] < v3[k]) {
			result.push_back(v1[l]);
			l++;
		} else if(v2[r] < v3[k] && v2[r] < v1[l]) {
			result.push_back(v2[r]);
			r++;
		}else {
            result.push_back(v3[k]);
            k++;
        }
	}
	while (l < v1.size() && r < v2.size()) {
		if(v1[l] < v2[r]){
            result.push_back(v1[l]);
		    l++;
        }
        else{
            result.push_back(v2[r]);
            r++;
        }
	}
	while (l < v1.size() && k < v3.size()) {
		if(v1[l] < v3[k]){
            result.push_back(v1[l]);
		    l++;
        }
        else{
            result.push_back(v3[k]);
            k++;
        }
	}
	while (r < v2.size() && k < v3.size()) {
		if(v2[r] < v3[k]){
            result.push_back(v2[r]);
		    r++;
        }
        else{
            result.push_back(v3[k]);
            k++;
        }
	}
	while (r < v2.size()) {
		result.push_back(v2[r]);
		r++;
	}
	while (l < v1.size()) {
		result.push_back(v1[l]);
		l++;
	}
	while (k < v3.size()) {
		result.push_back(v3[k]);
		k++;
	}

	return result;
}
int main() {
    

    return 0;
}