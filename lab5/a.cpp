#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
struct MinHeap {
	vector<ull> heap;

	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int right(int i) {
		return 2 * i + 2;
	}
	void insert(ull value) {
		this->heap.push_back(value);
		int i = this->heap.size() - 1;
		while (i != 0 && this->heap[parent(i)] > this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
	ull extactMin() {
		if (this->heap.size() == 0) return INT_MAX;
		if (this->heap.size() == 1) {
			ull root = this->heap[0];
			this->heap.pop_back();
			return root;
		}
		ull root = this->heap[0];
		this->heap[0] = this->heap[this->heap.size() - 1];
		this->heap.pop_back();
		this->heapify(0);
		return root;
	}
	void heapify(int i) {
		int l = this->left(i);
		int r = this->right(i);
		int smallest = i;
		if (l < this->heap.size() && this->heap[l] < this->heap[i])
			smallest = l;
		if (r < this->heap.size() && this->heap[r] < this->heap[smallest])
			smallest = r;
		if (smallest != i) {
			swap(this->heap[i], this->heap[smallest]);
			this->heapify(smallest);
		}
	}
};

int main() {
	MinHeap* heap1 = new MinHeap();
	ull n, x;
    cin >> n;
    while(n--){
        cin >> x;
        heap1->insert(x);
    }

    ull res = 0;
    while(heap1->heap.size() > 1){
        ull tmp = heap1->extactMin();
        ull tmp1 = heap1->extactMin();
		ull summ = tmp + tmp1;
        res += summ;
        heap1->insert(summ);
    }
    cout << res;
	return 0;
}