#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
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
    Node* head;
    Node* tail;
    int val;
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
    int getNearest(int k){
        Node* cur = this->head;
        int min = 1e9, minpos = -1;
        int cnt = 0;
        while(cur){
            if(abs(k - cur->val) < min){
                min = cur->val;
                minpos = cnt;
            }
            cur = cur->next;
            cnt++;
        }
        return min;
    }
    void print(){
        Node* cur = this->head;
        while(cur){
            cout << cur->val << ' ';
            cur = cur->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList* ll = new LinkedList();
    int n, k;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        ll->push_back(a);
    }
    cin >> k;
    ll->print();
    cout << ll->getNearest(k);
    return 0;
}
