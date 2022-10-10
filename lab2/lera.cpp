#include <bits/stdc++.h>
using namespace std;


struct Node{
    int val;
    Node *next;
    Node *prev;

    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

struct Deque{
    int size;
    Node *head;
    Node *tail;

    Deque(){
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    bool isEmpty(){
        return size == 0;
    }

    void pushBack(int val){
        Node *newNode = new Node(val);
        if(this->isEmpty()){
            this->head = newNode;
            this->tail = newNode;
        }else{
            this->tail->next = newNode;
            newNode->prev = this->tail;
            this->tail = newNode;
        }
        this->size++;
    }

    void pushFront(int val){
        Node *newNode = new Node(val);
        if(this->isEmpty()){
            this->head = newNode;
            this->tail = newNode;
        }else{
            this->head->prev = newNode;
            newNode->next = this->head;
            this->head = newNode;
        }
        this->size++;
    }

    void popFront(){
        if(this->isEmpty()){
            return;
        }else{
            Node *cur = this->head;
            head = head->next;
            delete(cur);
        }
        size--;
    }

    void popBack(){
        if(this->isEmpty()){
            return;
        }else{
            Node *cur = this->tail;
            this->tail = this->tail->prev;
            this->tail->next = NULL;
            delete(cur);
        }
        size--;
    }

    int getBack(){
        return this->tail->val;
    }

    void print() {
        Node *cur = this->head;
        while (cur != NULL) {
        cout << cur->val << " ";
        cur = cur->next;
        }
        cout << endl;
    }

    int findMax(){
        Node *cur = this->head;
        int max = 0;
        while(cur != NULL){
            if(cur->val > max){
                max = cur->val;
            }
            cur = cur->next;
        }
        return max;
    }

    int findIndex(int a){
        Node *cur = this->head;
        int cnt = 0;
        while(cur->val != a){
            cur=cur->next;
            cnt++;
        }
        return cnt;
    }
};

int main(){
    Deque d;
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     cout << a[i] << ' ';
    // }

    int odi = 1;
    int neo = 1;
    d.pushBack(1);
    for(int i = 0; i < n - 1; i++){
        if(a[i] == a[i + 1]){
            odi++;
            d.pushBack(odi);
        }
        else{
            odi = 1;
            d.pushBack(neo);
        }
    }
    d.popBack();
    // for(int i = 0; i < n ;i++){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
    // d.print();

    int l = d.findMax();
     for(int i = n-1; i >= 0; i--){
        if(d.getBack() == l){
            cout << a[i] << ' ';
            d.popBack();
        }else{
            d.popBack();
        }
     }

    return 0;
}