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
        Node *cur = this->head;
        while(cur){
            if(cur->val == val)return;
            cur = cur->next;
        }
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
    int sum = (ll->size * (ll->size + 1)) / 2;
    for(int i = 0; i < ll->size; i++){
        sum -= ll->head->val;
        ll->head = ll->head->next;
    }
    cout << sum << endl;
    return 0;
}