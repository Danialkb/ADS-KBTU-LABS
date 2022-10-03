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

    void add(int x){
        if(root == NULL){
            root = new Node();
            root->val = x;
            root->left = NULL;
            root->right = NULL;
        }
        else if (x < root->val)root->left = add(x);
        else root->right = add(x);
    }

};
    


int main() {
    
    
    
    
    
    return 0;
}