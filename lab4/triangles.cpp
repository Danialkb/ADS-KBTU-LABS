#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        this->left = this->right = nullptr;
    }
};

struct BST{
    Node *root;
    BST(){
        this->root = nullptr;
    }
private:
    Node* _insert(Node* cur, int val){
        if(!cur){
            return new Node(val);
        }
        if(cur->val < val){
            cur->right = _insert(cur->right, val);
        }
        else cur->left = _insert(cur->left, val);
        return cur;
    }
    void _preorder(Node* cur){
        if(!cur)return;
        cout << cur->val << ' ';
        _preorder(cur->left);
        _preorder(cur->right);
    }


    void _solve(Node *cur, vector<int> &res){
        if(!cur)return;
        int i = 0;
        Node *left = cur->left, *right = cur->right;
        while (left && right) {
            res[i]++;
            i++;
            left = left->left;
            right = right->right;
        }
        _solve(cur->left, res);
        _solve(cur->right, res);
    }

public:
    void insert(int val){
        this->root = _insert(this->root, val);
    }
    void preorder(){
        this->_preorder(this->root);
    }

    void solve(vector<int> &res){
        _solve(this->root, res);
    }

};

int main() {
    int n;
    cin >> n;
    vector<int> res(n-1);
    BST b;
    while(n--){
        int x;
        cin >> x;
        b.insert(x);
    }

    b.solve(res);

    for(int i = 0; i < res.size(); i++)cout << res[i] << ' ';
    cout << endl;

    return 0;
}