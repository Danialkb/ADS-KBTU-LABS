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
    Node* add(int x, Node *root){
        if(root == nullptr){
            root = new Node(x);
        }
        else if (x < root->val)root->left = add(x, root->left);
        else root->right = add(x, root->right);
        return root;
    }

public:
    void add(int x){
        this->root = add(x, root);
    }


};


int main() {
    int n;
    cin >> n;
    BinSearchTree tree;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if(s == "insert"){
            int x;
            cin >> x;
            tree.add(x);
        }
        
    }

    return 0;
}