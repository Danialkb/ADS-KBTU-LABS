#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int binSearch(int target, string c){
	int left = 0;
	int right = arr.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
        if(target < arr[0]){
            return 0;
        }else if(target > arr[arr.size()-1]){
            return arr.size()-1;
        }
        if(target > arr[mid] && target < arr[mid + 1]){
            if(c =="l1" || c =="l2"){
                return mid + 1;
            }
            return mid;
        }if (arr[mid] == target){
			return mid;
		}else if (arr[mid] > target){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}

    return false;

}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k, a;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end());

    // for(int i = 0; i < arr.size(); i++) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl << binSearch(112460520, "l2") << endl;
    int cnt = 0;
    for(int i = 0; i < k; i++) {
        int l1, r1, l2, r2;
        int cnt = 0;
        cin >> l1 >> r1;
        cin >> l2 >> r2;
        if(l2 >= l1 && r2 <= r1){
            cnt += (binSearch(r1, "r1") - binSearch(l1, "l1") + 1);
            cout << cnt << endl;
            continue;
        }
        if(l1 >= l2 && r1 <= r2){
            cnt += (binSearch(r2, "r2") - binSearch(l2, "l2") + 1);
            cout << cnt << endl;
            continue;
        }
        if(l2 <= r1){
            l2 = r1 + 1;
        }
        cnt += (binSearch(r1, "r1") - binSearch(l1, "l1")+1);
        // cout<< binSearch(r1, "l1")<<" "<<binSearch(r1, "r1")<<" "<<binSearch(l2, "l2")<<" "<<binSearch(r2,"r2")<<endl;;
        // cout << cnt << endl;
        cnt += (binSearch(r2, "r2") - binSearch(l2, "l2")+1);
        // cout << (binSearch(r2) - binSearch(l2)+1) << endl;
        cout<<cnt<<endl;
    }

    return 0;
}