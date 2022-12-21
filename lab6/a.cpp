#include <bits/stdc++.h>
using namespace std;

bool isvowel(char c){
    if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I'  || c == 'o' || c == 'O' || c == 'u' || c == 'U')return true;
    return false;
}

bool compare(char &c, char &pivo){
    if(isvowel(c) && !isvowel(pivo))return true;
    if(isvowel(c) && isvowel(pivo))return c < pivo;
    if(!isvowel(c) &&  isvowel(pivo))return false;
    return c < pivo;
}

int partition(string &s, int left, int right) {
	char pivot = s[right];
	int index = left;
	for (int i = left; i < right; i++) {
		if (compare(s[i], pivot)) {
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    quick_sort(s, 0, s.size() - 1);
    cout << s << endl;
    return 0;
}