#include <bits/stdc++.h>
using namespace std;

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

    int _height(Node *cur, int &d){
        if(!cur)return 0;
        int left = _height(cur->left, d);
        int right = _height(cur->right, d);
        d = max(d, left + right + 1);
        return max(left, right) + 1;
    }
    
public:
    void add(int x){
        this->root = _add(x, root);
    }

    int getDiameter(){
        int d = 0;
        _height(this->root, d);
        return d;
    }

};


int main() {
    int n, x;
    cin >> n;
    BinSearchTree tree;
    while(n--){
        cin >> x;
        tree.add(x);
    }
    
    cout << tree.getDiameter();

    return 0;
}