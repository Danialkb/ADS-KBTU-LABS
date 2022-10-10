#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
struct MaxHeap {
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
		while (i != 0 && this->heap[parent(i)] < this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
	ull extactMax() {
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
		if (l < this->heap.size() && this->heap[l] > this->heap[i])
			smallest = l;
		if (r < this->heap.size() && this->heap[r] > this->heap[smallest])
			smallest = r;
		if (smallest != i) {
			swap(this->heap[i], this->heap[smallest]);
			this->heapify(smallest);
		}
	}
    void print(){
        for(int i = 0; i < this->heap.size(); i++) {
            cout << this->heap[i] << ' ';
        }
        cout << endl;
    }
};

int main() {
	MaxHeap heap1;
	ull n, x;
    cin >> n;
    while(n--){
        cin >> x;
        heap1.insert(x);
    }

    // heap1.print();
    while(heap1.heap.size() > 1){
        ull y = heap1.extactMax();
        ull x = heap1.extactMax();
        if(x != y){
            heap1.insert(y - x);
        }
    }
    if(heap1.heap.size() == 0)cout << 0 << endl;
    else cout << heap1.extactMax() << endl;
	return 0;
}