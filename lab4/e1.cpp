#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};

struct BinSearchTree{
    Node* root;
    BinSearchTree() {
        root = nullptr;
    }
private:
    void add(Node *root,int y,int z){
        if(z == 0){
            root->left = new Node(y);
        }
        else root->right = new Node(y);
        // if(root == nullptr){
        //     root = new Node(x);

        // }else{
        //     Node * cur = find(x);
        //     if(z==0){
        //         cur->right = add(y,cur->right,x,z);
        //     }else{
        //         cur->left = add(y,cur->left,x,z);
        //     }
        // }
        // return root;
        
    }

    Node* find(int x, Node * n){
        if(n->val == x){
            return n;
        }else{
            find(x, n->left);
            find(x, n->right);
        }
        return n;
    }
public:
    void print(Node * n){
        if(n!=nullptr){
            print(n->left);
            cout<<n->val<<endl;
            print(n->right);
        }
    }

    Node* find(int x){
        return find(x, this->root);
    }
    
    void add(int x, int y, int z){
        add(find(x), y, z);
    }

};
    


int main() {
    BinSearchTree * bst;

    int n;
    cin >> n;
    bst->root = new Node(1);
    for(int i=0;i<n;i++){
        int x, y, z;
        cin>>x>>y>>z;
        bst->add(x, y, z);
    } 
    bst->print(bst->root);
    
    
    return 0;
}