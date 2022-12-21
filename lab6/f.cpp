#include <bits/stdc++.h>
using namespace std;

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

bool comp(pair<pair<string, string>, double> &p1, pair<pair<string, string>, double> &p2){
    if(p1.second == p2.second){
        for(int i = 0; i < p1.first.first.size() && i < p2.first.first.size(); i++){
            if(p1.first.first[i] < p2.first.first[i])return true;
            if(p1.first.first[i] > p2.first.first[i])return false;
        }
        for(int i = 0; i < p1.first.second.size() && i < p2.first.second.size(); i++){
            if(p1.first.second[i] < p2.first.second[i])return true;
            if(p1.first.second[i] > p2.first.second[i])return false;
        }
    }

    return p1.second < p2.second;
}

int partition(vector<pair<pair<string, string>, double> > &a, int left, int right){
    int ind = left;
    pair<pair<string, string>, double> pivot = a[right];
    for(int i = left; i < right; i++){
        if(comp(a[i], pivot)){
            swap(a[i], a[ind]);
            ind++;
        }
    }
    swap(a[ind], a[right]);
    return ind;
}

void quick_sort(vector<pair<pair<string, string>, double> > &a, int left, int right){
    if(left < right){
        int p = partition(a, left, right);
        quick_sort(a, left, p-1);
        quick_sort(a, p+1, right);
    }
}

int main() {
    // freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<pair<pair<string, string>, double> > gpa;
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
        gpa.push_back(make_pair(make_pair(s1, s2), calculateGPA(v)));
    }

    quick_sort(gpa, 0, gpa.size() - 1);

    for(int i = 0; i < gpa.size(); i++){
        cout << gpa[i].first.first << " " << gpa[i].first.second << " " << fixed << setprecision(3) << gpa[i].second << endl;
    }

    return 0;
}