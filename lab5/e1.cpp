#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
struct MinHeap {
    ull cookies;
	vector<ull> heap;
    int k;
    MinHeap(int  k){
        this->k = k;
    }

	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int right(int i) {
		return 2 * i + 2;
	}
    void check(int val){
        if(this->heap.size() == this->k){
            int min = extractMin();
            if(min > val){
                insert(min);
                return;
            }
            else {
                cookies -= min;
                cookies += val;
                insert(val);
                return;
            }
        }
        insert(val);
        cookies += val;
    }
	void insert(ull value) {
		this->heap.push_back(value);
		int i = this->heap.size() - 1;
		while (i != 0 && this->heap[parent(i)] > this->heap[i]) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
	ull extractMin() {
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
	int n, k;
    cin >> n >> k;
    MinHeap *h = new MinHeap(k);
    while(n--){
        string s;
        cin >> s;
        if(s == "print"){
            cout << h->cookies << endl;
        }
        else{
            int x;
            cin >> x;
            h->check(x);
        }
    }
	return 0;
}