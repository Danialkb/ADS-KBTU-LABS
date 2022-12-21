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

bool compare(Student** s1, Student** s2){
    if((*s1)->gpa == (*s2)->gpa){
        if((*s1)->surname == (*s2)->surname)return (*s1)->name < (*s2)->name;
        return (*s1)->surname < (*s2)->surname;
    }
    return (*s1)->gpa < (*s2)->gpa;
}

vector<Student*> merge(vector<Student*> left, vector<Student*> right) {
	vector<Student*> result;
	int l = 0, r = 0;
	while (l < left.size() && r < right.size()) {
		if (compare(&right[r], &left[l])) {
			result.push_back(right[r]);
			r++;
		}
        else{
            result.push_back(left[l]);
            l++;
        }
	}
	while (l < left.size()) {
		result.push_back(left[l]);
		l++;
	}
	while (r < right.size()) {
		result.push_back(right[r]);
		r++;
	}
	return result;
}

vector<Student*> merge_sort(vector<Student*> &a) {
	if (a.size() == 1) return a;
    vector<Student*> al, ar;
    int n = a.size();
    for (int i = 0; i < n / 2; i++) {
        al.push_back(a[i]);
    }
    for (int i = n / 2; i < n; i++) {
        ar.push_back(a[i]);
    }
    al = merge_sort(al);
    ar = merge_sort(ar);
    return merge(al, ar);
}

int main() {
    // freopen("output.txt", "w", stdout);
    vector<Student*> studs;
    int n;
    cin >> n;
    // vector<Student*> students;
    for(int i = 0; i < n; i++){
        string s1, s2;
        int x;
        cin >> s1 >> s2 >> x;
        double sum1 = 0, sum2 = 0;
        while(x--){
            string mark;
            int credit;
            cin >> mark >> credit;
            if(mark == "A+")sum1 += (4.00 * credit);
            if(mark == "A")sum1 += (3.75 * credit);
            if(mark == "B+")sum1 += (3.50 * credit);
            if(mark == "B")sum1 += (3.00 * credit);
            if(mark == "C+")sum1 += (2.50 * credit);
            if(mark == "C")sum1 += (2.00 * credit);
            if(mark == "D+")sum1 += (1.50 * credit);
            if(mark == "D")sum1 += (1.00 * credit);
            sum2 += credit;
        }
        Student *cur;
        if(sum2 != 0)cur = new Student(sum1/sum2, s1, s2);
        else cur = new Student(0.0, s1, s2);
        studs.push_back(cur);
    }
    studs = merge_sort(studs);
    for(int i = 0; i < n; i++){
        studs[i]->print();
    }
    

    return 0;
}