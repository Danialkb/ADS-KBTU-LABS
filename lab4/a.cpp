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
public:
    void add(int x){
        this->root = add(x, root);
    }
    bool isPeak(string s){
        Node *cur = this->root;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L'){
                cur = cur->left;
                if(!cur)return false;
            }
            else{
                cur = cur->right;
                if(!cur)return false;
            }
        }
        return true;
    }
};
    


int main() {
    BinSearchTree bst;

    int n, k, x;
    cin >> n >> k;
    string s;
    while(n--){
        cin >> x;
        bst.add(x);
    }

    while(k--){
        cin >> s;
        bst.isPeak(s) ? cout << "YES\n" : cout << "NO\n";
    }
    
    
    
    
    return 0;
}