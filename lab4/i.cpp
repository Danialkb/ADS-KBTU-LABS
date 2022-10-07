#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *left;
    Node *right;
    int multiplicity;
    Node(int val){
        this->val = val;
        this->left = this->right = nullptr;
        this->multiplicity = 1;
    }
};

struct BinSearchTree{
    Node* root;
    BinSearchTree() {
        root = nullptr;
    }
private:
    Node* add(int x, Node *cur){
        if(cur == nullptr){
            cur = new Node(x);
        }
        else if(x == cur->val){
            cur->multiplicity++;
            return cur;
        }
        else if (x < cur->val)cur->left = add(x, cur->left);
        else cur->right = add(x,cur->right);
        return cur;
    }
    int find(int x, Node *cur){
        if(!cur)return 0;
        if(x == cur->val){
            return cur->multiplicity;
        }
        else if(x < cur->val)return find(x, cur->left);
        else return find(x, cur->right);
    }
    int rightmost(Node *cur){
        if(!cur)return -1;
        if(!cur->right)return cur->val;
        return rightmost(cur->right);
    }
    Node *_delete(int x, Node *cur){
        if(!cur)return nullptr;
        if(x < cur->val){
            cur->left = _delete(x, cur->left);
        }
        else if (x > cur->val){
            cur->right = _delete(x, cur->right);
        }
        else{
            if(cur->multiplicity != 0){
                cur->multiplicity--;
                return cur;
            }
            else{
                if(!cur->left && !cur->right){
                    delete cur;
                    return nullptr;
                }
                else if(cur->left && !cur->right){
                    Node *temp = cur->left;
                    delete cur;
                    return temp;
                }
                else if(!cur->left && cur->right){
                    Node *temp = cur->right;
                    delete cur;
                    return temp;
                } 
                else if(cur->left && cur->right){
                    cur->val = rightmost(cur->left);
                    cur->left = _delete(cur->val, cur->left);
                }
            }
        }
        return cur;
    }
    

public:
    void add(int x){
        this->root = add(x, root);
    }

    int getCnt(int x){
        return find(x, root);
    }

    void del(int x){
        this->root = _delete(x, root);
    }

};


int main() {
    // freopen ("input.txt" , "r", stdin);
    // freopen ("output.txt" , "w", stdout);

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
        else if(s == "cnt"){
            int x;
            cin >> x;
            cout << tree.getCnt(x) << endl;
        }
        else{
            int x;
            cin >> x;
            tree.del(x);
        }
    }

    return 0;
}