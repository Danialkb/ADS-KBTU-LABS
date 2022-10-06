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

Node *find(Node *node, int target){
    if(node->val == target)return node;
    return find(node->left, target);
    return find(node->right, target);
}
Node *insert(Node *cur, int y, int z){
    if(z == 0){
        cur->left = new Node(y);
    }
    else if(z == 1){
        cur->right = new Node(y);
    }
    return cur;

}

void print(Node* tree){
    if(!tree)return;
    cout << tree->val << ' ';
    print(tree->left);
    print(tree->right);
}
int main() {
    int n, x, y, z;
    cin >> n;
    cin >> x >> y >> z;
    Node *root = new Node(1);
   while(n--){
        int x, y, z;
        cin >> x >> y >> z;
        if(!root)root = new Node(x);
        root = insert(find(root, x), y, z);
   }
    print(root);
    return 0;
}