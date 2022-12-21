#include <bits/stdc++.h>
using namespace std;
int partition(string &s, int left, int right) {
	char pivot = s[right];
	int index = left;
	for (int i = left; i < right; i++) {
		if (s[i] < pivot) {
			swap(s[i], s[index]);
			index++;
		}
	}
	swap(s[index], s[right]);
	return index;
}

void quick_sort(string &s, int left, int right) {
	if (left < right) {
		int p = partition(s, left, right);
		quick_sort(s, left, p - 1);
		quick_sort(s, p + 1, right);
	}
}

int main() {
    string s = "";
    int n;
    cin >> n;
    while (n--){
        char x;
        cin >> x;
        s += x;
    }

    

    return 0;
}