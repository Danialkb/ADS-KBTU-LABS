#include <bits/stdc++.h>
using namespace std;

vector<int> gSum;
int sum = 0;

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
    Node* _add(int x, Node *root){
        if(root == nullptr){
            root = new Node(x);
        }
        else if (x < root->val)root->left = _add(x, root->left);
        else root->right = _add(x, root->right);
        return root;
    }

    void _someorder(Node *cur){
        if(!cur)return;
        _someorder(cur->right);
        sum += cur->val;
        gSum.push_back(sum);
        _someorder(cur->left);
    }
    
    void _preorder(Node *cur){
        if(!cur)return;
        cout << cur->val << ' ';
        _preorder(cur->left);
        _preorder(cur->right);
    }
public:
    void add(int x){
        this->root = _add(x, root);
    }

    void someorder(){
        _someorder(this->root);
    }

    void preorder(){
        _preorder(this->root);
        cout <<endl;
    }
};


int main() {
    int n, x;
    cin >> n;
    BinSearchTree tree;
    BinSearchTree tree1;
    for(int i = 0; i < n; i++){
        cin >> x;
        tree.add(x);
    }

    tree.someorder();

    for(int i = 0; i < gSum.size(); i++)tree1.add(gSum[i]);

    tree1.preorder();
    

    return 0;
}