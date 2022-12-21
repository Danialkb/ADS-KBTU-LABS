#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
};

struct BinSearchTree{
    Node* root;
    BinSearchTree() {
        root = nullptr;
    }
private:
    Node* add(int x, Node *root){
        if(root == nullptr){
            root = new Node();
            root->val = x;
            root->left = nullptr;
            root->right = nullptr;
        }
        else if (x < root->val)root->left = add(x, root->left);
        else root->right = add(x, root->right);
        return root;
    }
    void _preorder(Node *cur){
        if(!cur)return;
        cout << cur->val << ' ';
        _preorder(cur->left);
        _preorder(cur->right);
    }   


public:
    void add(int x){
        if(!this->root)this->root = add(x, this->root);
        else add(x, root);
    }
    
    void preorder(){
        _preorder(this->root);
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

    b.preorder();


    return 0;
}