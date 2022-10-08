#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
	Node(){
		this->val = 0;
        this->left = this->right = nullptr;
	}
    Node(int val){
        this->val = val;
        this->left = this->right = nullptr;
    }
};



Node *insert(Node *node, int x,  int y, int z){
	queue<Node*> q;
	q.push(node);
	while(!q.empty()){
		Node *tmp = q.front();
		q.pop();
		if(q.front()->val == x){
			if(z == 0){
				tmp->left = new Node(y);
				return node;
			}
			else {
				tmp->right = new Node(y);
				return node;
			}
		}
		if(tmp->left)q.push(tmp->left);
		if(tmp->right)q.push(tmp->right);
	}
	return node;
}

void preorder(Node *node){
	if(!node)return;
    cout << node->val << " ";
	preorder(node->left);
    preorder(node->right);
}
int main() {
    int n, x, y, z;
    cin >> n;
    Node *root = new Node(1);

	for(int i = 0; i < n; i++){
		cin >> x >> y >> z;
        root = insert(root, x, y, z);
	}
	preorder(root);
    return 0;
}