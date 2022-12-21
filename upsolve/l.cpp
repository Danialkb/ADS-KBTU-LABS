#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
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
    void _solve(Node* cur){
        if(!cur)return;
        if(!cur->left && !cur->right)cnt++;
        _solve(cur->left);
        _solve(cur->right);

    }
public:
    void add(int x){
        this->root = _add(x, root);
    }

    void solve(){
        _solve(root);
    }

};

int main() {
    int n;
    cin >> n;
    BinSearchTree b;
    while(n--){
        int x;
        cin >> x;
        b.add(x);
    }

    b.solve();
    cout << cnt << endl;
    return 0;
}