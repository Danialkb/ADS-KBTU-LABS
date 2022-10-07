#include <bits/stdc++.h>
using namespace std;


struct Node{
    int val;
    Node* left;
    Node* right;
};

struct BinSearchTree{
    Node* root;
    int cnt;
    BinSearchTree() {
        root = nullptr;
        cnt = 0;
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
    int _height(Node *cur){
        if(!cur)return 0;
        return 1 + max(_height(cur->left), _height(cur->right));
    }
    void _sumLevels(vector<int> &v, int level, Node *cur){
        if(!cur)return;
        v[level] += cur->val;
        _sumLevels(v, level + 1, cur->left);
        cout << cur->val << ' ' << level << endl;
        _sumLevels(v, level + 1, cur->right);
    }

public:
    void add(int x){
        this->root = add(x, root);
    }
    
    void sumLevels(vector<int> &v){
        _sumLevels(v, 0, this->root);
    }

    int height(){
        return _height(this->root);
    }
};

int main() {
    vector<int> res;
    int n, value;
    cin >> n;
    BinSearchTree tree;
    while(n--){
        cin >> value;
        tree.add(value);
    }
    res.resize(tree.height());

    tree.sumLevels(res);
    // cout << res.size() << endl;
    // for(int i = 0; i < res.size(); i++){
    //     cout << res[i] << " ";
    // }
    cout << endl;
    return 0;
}