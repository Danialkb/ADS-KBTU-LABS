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
    int getSize(Node *cur){
        if(cur == nullptr)return 0;
        cnt++;
        getSize(cur->left);
        getSize(cur->right);
        return cnt;
    }
    Node* find(int x){
        Node *cur = root;
        while(cur->val != x){
            if(cur->val > x){
                cur = cur->left;
            }
            else cur = cur->right;
        }
        return cur;
    }
    void print(Node *cur){
        if(cur == nullptr)return;
        cout << cur->val << ' ';
        print(cur->left);
        print(cur->right);
    }
public:
    void add(int x){
        this->root = add(x, root);
    }
    
    void print(int x){
        return this->print(find(x));
    }

};
    


int main() {
    BinSearchTree bst;

    int n, k, x;
    cin >> n;
    string s;
    while(n--){
        cin >> x;
        bst.add(x);
    }
    
    cin >> x;

    bst.print(x);
    cout << endl;
    
    
    
    return 0;
}