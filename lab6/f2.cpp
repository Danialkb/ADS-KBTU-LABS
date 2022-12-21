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

void quick_sort(vector<Student*> &a, int l, int r) {
    if (r < l + 1) return;
    int mid = (l + r) / 2;
    Student* pivot = a[mid];
    int j = l;
    swap(a[r], a[mid]);
    for (int i = l; i <= r; i++) {
        if (compare(&a[i], &pivot)) {
            swap(a[i], a[j]);
            j++;
        }
    }
    swap(a[j], a[r]);
    quick_sort(a, l, j - 1);
    quick_sort(a, j + 1, r);
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
    quick_sort(studs, 0, n - 1);
    for(int i = 0; i < n; i++){
        studs[i]->print();
    }
    

    return 0;
}