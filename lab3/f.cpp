#include <bits/stdc++.h>
using namespace std;

int binSearch(vector<int> &arr, int &target){
    if(target >= arr[arr.size()-1]){
            return arr.size()-1;
    }

	int left = 0;
	int right = arr.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
        if(target>arr[mid] && target<arr[mid+1]){
            return mid;
        }
		if (arr[mid] == target )
		{
            for(int i=mid+1;i<arr.size();i++){
                if(arr[i] != target){
                    return i-1;
                }
            }
            return arr.size();
		}
		else if (arr[mid] > target)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

    return -1;

}

int main() {
    int n, k, a;
    cin >> n;
    vector<int> v;

    while(n--){
        cin >> a;
        v.push_back(a);
    }
    cin >> k;
    sort(v.begin(), v.end());
    while(k--){
        int cnt = 0, sum = 0;
        cin >> a;
        int nnn = binSearch(v,a);
        for(int i=0;i<=nnn;i++){
            cnt+=v[i];
        }
        cout << nnn+1 << ' ' << cnt << endl;
    }

    return 0;
}