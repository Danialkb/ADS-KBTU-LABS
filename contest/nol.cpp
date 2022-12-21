#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    int sum = 0, mx = -1e9;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}
	if(sum%2 != 0 || mx*2 > sum)cout<<"NO\n";
	else cout<<"YES\n";

    return 0;
}