#include <bits/stdc++.h>
using namespace std;
long long sum = 0;
struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val = val;
        this->left = this->right = nullptr;
    }
};

struct BinSearchTree{
    Node* root;
    BinSearchTree() {
        root = nullptr;
    }
private:
    Node* _add(int x, Node *cur){
        if(cur == nullptr)return new Node(x);
        if(cur->val == x)return cur;
        else if (x < cur->val)cur->left = _add(x, cur->left);
        else cur->right = _add(x, cur->right);
        return cur;
    }
    void _solve(Node* cur, int level){
        if(!cur)return;
        sum += (cur->val - level);
        _solve(cur->left, level + 1);
        _solve(cur->right, level + 1);
    }
public:
    void add(int x){
        this->root = _add(x, root);
    }

    void solve(){
        _solve(root, 0);
    }

};

int main() {
    BinSearchTree b;
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        b.add(x);
    }

    b.solve();
    cout << sum << endl;

    return 0;
}