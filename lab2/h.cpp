#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *next;
    Node(){
        this->val = 0;
        this->next = NULL;
    }
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
struct LinkedList{
    Node* head;
    Node *tail;
    int size;
    int val;
    LinkedList(){
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    void push_back(int val){
        Node *tmp = new Node(val);
        if(!this->head){
            this->head = tmp;
            this->tail = tmp;
        }
        else{
            this->tail->next = tmp;
            this->tail = tmp;
        }
        this->size++;
    }
    void insertAt(int val, int i){
        if(i == 0){
            Node *tmp = new Node(val);
            tmp->next = this->head;
            this->head = tmp;
        }
        else if(i == this->size)this->push_back(val);
        else{
            Node *tmp = new Node(val);
            Node *cur = this->head;
            for(int j = 0; j < i - 1; j++)cur = cur->next;
            tmp->next = cur->next;
            cur->next = tmp;
        }
    }
    void print(){
        Node *cur = this->head;
        while(cur){
            cout << cur->val << ' ';
            cur = cur->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList *ll = new LinkedList();
    int n, a, val, pos;
    cin >> n;
    while(n--){
        cin >> a;
        ll->push_back(a);
    }
    cin >> val >> pos;
    ll->insertAt(val, pos);
    ll->print();
    return 0;
}