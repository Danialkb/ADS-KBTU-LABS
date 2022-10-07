#include <bits/stdc++.h>
using namespace std;
struct Node{
    int value;
    Node *left;
    Node *right;
    Node(int val){
        this->value = val;
        this->left = this->right = nullptr;
    }
};

struct BinaryTree {
	Node* root;
	BinaryTree() {
		root = nullptr;
	}
private:
	void preorder(Node* node) {
		if (!node) return;
		cout << node->value << " ";
		this->preorder(node->left);
		this->preorder(node->right);
	}
    Node *find(int target, Node* node) {
        if (!node) return nullptr;
        if (node->value == target) return node;
        else if (node->value < target)node->right = find(target, node->right);
        else node->left = find(target, node->left);
        return node;
    }
	void insert(int value, Node* cur) {
		if (!cur)return;
		else {
			if (!cur->left)
				this->insert(value, cur->left);
			else if (!cur->right)
				this->insert(value, cur->right);

		}
	}
	Node* findBlankNode() {
		queue<Node*> q;
		q.push(this->root);
		while (q.front()->left && q.front()->right) {
			if (q.front()->left) q.push(q.front()->left);
			if (q.front()->right) q.push(q.front()->right);
			q.pop();
		}
		return q.front();
	}
public:

	void preorder() {
		this->preorder(this->root);
    }
	void insert(int value) {
		if (!this->root) {
			this->root = new Node(value);
		}
		else {
			Node* cur = this->findBlankNode();
			if (!cur->left)
				cur->left = new Node(value);
			else if (!cur->right)
				cur->right = new Node(value);
		}
	}
	void remove(int value) {
		queue<Node*> q;
		q.push(this->root);
		while (q.front()->left->value != value && q.front()->right->value != value) {
			if (q.front()->left) q.push(q.front()->left);
			if (q.front()->right) q.push(q.front()->right);
			q.pop();
		}
		Node* cur = q.front();
		if (cur->left->value == value)
			cur->left = nullptr;
		else
			cur->right = nullptr;
	}
};

int main() {
    BinaryTree tree;
    int n, x, y, z;
    cin >> n;
    cin >> x >> y >> z;
    
    return 0;
}