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

Node* makeBalanced(vector<int> &arr, int start, int end){
            if (start > end)return NULL;

            int mid = (start + end)/2;
            Node *root = new Node(arr[mid]);

            root->left = makeBalanced(arr, start, mid - 1);
            root->right = makeBalanced(arr, mid + 1, end);

            return root;
}

void _preorder(Node *cur){
        if(!cur)return;
        cout << cur->val << ' ';
        _preorder(cur->left);
        _preorder(cur->right);
}

int main() {
    vector<int> v;
    int n;
    cin>>n;
    for(int i = 0; i < pow(2, n) - 1; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    Node *root = makeBalanced(v, 0, v.size() - 1);
    _preorder(root);
    return 0;
}