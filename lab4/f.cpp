#include <bits/stdc++.h>
using namespace std;
int cnt;

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

    void _triangles(Node* cur){
        if(!cur)return;
        if(cur->left && cur->right)cnt++;
        _triangles(cur->left);
        _triangles(cur->right);
    }

public:
    void add(int x){
        this->root = add(x, root);
    }
    
    void triangles(){
        _triangles(this->root);
    }

};

int main() {
    int n;
    cin >> n;
    BinSearchTree tree;
    while(n--){
        int x;
        cin >> x;
        tree.add(x);
    }

    tree.triangles();
    cout << cnt << endl;
    
    return 0;
}