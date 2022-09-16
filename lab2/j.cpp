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
    int size;
    Node *head;
    Node *tail;
    LinkedList(){
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    void push_back(int val){
        this->size++;
        Node* tmp = new Node(val);
        if(!this->head){
            this->head = tmp;
            this->tail = tmp;
        }
        else{
            this->tail->next = tmp;
            this->tail = tmp;
        }
    }

    void sortBubble(){
        Node *cur = this->head;
        while(cur){
            Node *tmp = cur->next;
            while(tmp){
                if(tmp->val < cur->val)swap(tmp->val, cur->val);
                tmp = tmp->next;
            }
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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    LinkedList *ll = new LinkedList();
    int n, a;
    cin >> n;
    while(n--){
        cin >> a;
        ll->push_back(a);
    }
    ll->sortBubble();
    for(int i = 0; i < ll->size; i++){
        if(i != ll->head->val){
            cout << i << endl;
            return 0;
        }
        ll->head = ll->head->next;
    }
    cout << ll->size << endl;
    return 0;
}