#include <bits/stdc++.h>
using namespace std;

struct Student{
    double gpa;
    string name;
    string surname;
    Student(double gpa, string surname, string name){
        this->gpa = gpa;
        this->name = name;
        this->surname = surname;
    }
    void print(){
        cout << this->surname << " " << this->name << " " << fixed << setprecision(3) << this->gpa << endl;
    }
};

double calculateGPA(vector<pair<string, int> > &v){
    double sum1 = 0, sum2 = 0;
    for(int i=0; i < v.size(); i++){
        if(v[i].first == "A+")sum1 += (4.00 * v[i].second);
        if(v[i].first == "A")sum1 += (3.75 * v[i].second);
        if(v[i].first == "B+")sum1 += (3.50 * v[i].second);
        if(v[i].first == "B")sum1 += (3.00 * v[i].second);
        if(v[i].first == "C+")sum1 += (2.50 * v[i].second);
        if(v[i].first == "C")sum1 += (2.00 * v[i].second);
        if(v[i].first == "D+")sum1 += (1.50 * v[i].second);
        if(v[i].first == "D")sum1 += (1.00 * v[i].second);
        sum2 += v[i].second;
    }
    return sum1 / sum2;
}

bool compare(Student* s1, Student* s2){
    if(s1->gpa == s2->gpa){
        if(s1->surname == s2->surname)return s1->name > s2->name;
        return s1->surname > s2->surname;
    }
    return s1->gpa > s2->gpa;
}
struct MinHeap {
	vector<Student*> heap;
    int sz;
	int parent(int i) {
		return (i - 1) / 2;
	}
	int left(int i) {
		return 2 * i + 1;
	}
	int right(int i) {
		return 2 * i + 2;
	}
	void insert(Student *s) {
		this->heap.push_back(s);
		int i = this->heap.size() - 1;
		while (i != 0 && compare(this->heap[i], this->heap[parent(i)])) {
			swap(this->heap[parent(i)], this->heap[i]);
			i = parent(i);
		}
	}
	Student* extractMin() {
		// if (this->heap.size() == 0) return ;
		if (this->heap.size() == 1) {
			Student *root = this->heap[0];
			this->heap.pop_back();
			return root;
		}
		Student *root = this->heap[0];
		this->heap[0] = this->heap[this->heap.size() - 1];
		this->heap.pop_back();
		this->heapify(0);
		return root;
	}
	void heapify(int i) {
		int l = this->left(i);
		int r = this->right(i);
		int smallest = i;
		if (l < sz && compare(this->heap[l], this->heap[smallest]))
			smallest = l;
		if (r < sz && compare(this->heap[r], this->heap[smallest]))
			smallest = r;
		if (smallest != i) {
			swap(this->heap[i], this->heap[smallest]);
			this->heapify(smallest);
		}
	}

    void heapsort(){
        sz = this->heap.size();
        while(sz > 1){
            Student *tmp = heap[0];
            heap[0] = heap[sz-1];
            heap[sz-1] = tmp;
            sz--;
            this->heapify(0);
        }
    }

    void print(){
        for(int i = 0; i < this->heap.size(); i++){
            heap[i]->print();
        }
    }

};

int main() {
    // freopen("output.txt", "w", stdout);
    MinHeap m;
    int n;
    cin >> n;
    // vector<Student*> students;
    while(n--){
        string s1, s2;
        int x;
        cin >> s1 >> s2 >> x;
        vector<pair<string, int> > v;
        while(x--){
            string mark;
            int credit;
            cin >> mark >> credit;
            v.push_back(make_pair(mark, credit));
        }
        Student *cur = new Student(calculateGPA(v), s1, s2);
        m.insert(cur);
    }
    m.heapsort();
    m.print();
    

    return 0;
}