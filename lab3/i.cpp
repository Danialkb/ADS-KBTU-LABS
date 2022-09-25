#include <bits/stdc++.h>
using namespace std;

bool binSearch(vector<int> &arr, int &target)
{
	int left = 0;
	int right = arr.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid] == target)
		{
			return true;
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

    return false;

}

int main() {
    vector<int> v;
    int n, a, target; 
    cin >> n;
    while(n--){
        cin >> a;
        v.push_back(a);
    }

    cin >> target;

    binSearch(v, target) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
