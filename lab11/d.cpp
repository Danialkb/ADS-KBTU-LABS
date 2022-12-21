#include <bits/stdc++.h>
using namespace std;

struct Edge{
    int w, from, to;
    Edge(){}
    Edge(int weight, int from, int to){
        this->w = weight;
        this->from = from;
        this->to = to;
    }

    void print(){
        cout << this->w << ", " << this->from << ", " << this->to << endl;
    }

};

bool compare(Edge e1, Edge e2){
    return e1.w < e2.w;
}

vector<Edge> g;
vector<int> p;
int n, q, mincost = 0;

int dsu(int v) {
	if (v == p[v]) {
		return v;
	} else {
		return p[v] = dsu(p[v]);
	}
}

void dsuUnion(int a, int b) {
	a = dsu(a);
	b = dsu(b);
	if (a != b)
		p[a] = b;
}

int main() {
	cin >> n;
	p.resize(n);
	int x;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> x;
            if(i != j)g.push_back(Edge(x, i, j));
        }
    }


	sort(g.begin(), g.end(), compare);

    // for(int i = 0; i < g.size(); i++)g[i].print();

	for (int i = 0; i < n; ++i)
		p[i] = i;
	
	for (int i = 0; i < g.size(); ++i) {
		int u = g[i].from;
		int v = g[i].to;
		int cost = g[i].w;
		if (dsu(u) != dsu(v)) {
			mincost += cost;
			dsuUnion(u, v);
		}
	}

    cout << mincost << endl;

    return 0;
}