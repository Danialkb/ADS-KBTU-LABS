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
    Node *head;
    Node *tail;
    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }
    void push_back(int val){
        Node *tmp = new Node(val);
        if(!this->head){
            this->head = tmp;
            this->tail = tmp;
        }
        else {
            this->tail->next = tmp;
            this->tail = tmp;
        }
    }
    void delEven(){
        Node *cur = this->head;
        while(cur && cur->next){
            Node *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
            cur = cur->next;
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
    int n, a;
    cin >> n;
    while(n--){
        cin >> a;
        ll->push_back(a);
    }
    ll->delEven();
    ll->print();
    return 0;
}