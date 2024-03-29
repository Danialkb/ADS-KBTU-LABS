#include <bits/stdc++.h>
using namespace std;

struct MaxHeap {
	vector<long long> heap;

	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int right(int i) {
		return 2 * i + 2;
	}
	void insert(int value) {
		this->heap.push_back(value);
		int i = this->heap.size() - 1;
		while (i != 0 && this->heap[parent(i)] < this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
    int update(int i, int val){
        i--;
        heap[i] += val;
        while(i != 0 && heap[i] > heap[parent(i)]){
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
        return i + 1;
    }
    void print(){
        for(int i = 0; i < this->heap.size(); i++)cout << this->heap[i] << ' ';
        cout << endl;
    }
};
int main() {
    MaxHeap m;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        m.insert(x);
    }

    int k;
    cin >> k;
    while(k--){
        int i, val;
        cin >> i >> val;
        cout << m.update(i, val) << endl;
    }
    m.print();

    return 0;
}