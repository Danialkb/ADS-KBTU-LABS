#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    int cnt;
    Node *next;
    Node(){
        this->val = 0;
        this->next = NULL;
        this->cnt = 1;
    }
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->cnt = 1;
    }
};

struct LinkedList{
    Node *head;
    int size;
    LinkedList(){
        this->head = nullptr;
        this->size = 0;
    }
    void push_back(int val){
        if(!this->head){
            this->head = new Node(val);
            this->size++;
        }
        else {
            Node *cur = this->head;
            while(cur->next){
                if(cur->val == val){
                    cur->cnt++;
                    return;
                }
                cur = cur->next;
            }
            if(cur->val == val){
                    cur->cnt++;
                    return;
            }
            cur->next = new Node(val);

        }
    }

    void sort(){
        Node *cur = this->head;
        while(cur){
            Node *tmp = cur->next;
            while(tmp){
                if(cur->cnt < tmp->cnt){
                    swap(cur->cnt, tmp->cnt);
                    swap(cur->val, tmp->val);
                }
                if(cur->cnt == tmp->cnt){
                    if(tmp->val > cur->val){
                        swap(cur->val, tmp->val);
                    }
                }
                tmp = tmp->next;
            }
            cur = cur->next;
        }
    }

    void print() {
        Node* cur = head;
        while (cur != NULL) {
            cout << cur->val << " " << cur->cnt << endl;
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
    
    ll->sort();
    // ll->print();
    int modeNum = ll->head->cnt;

    while(ll->head && ll->head->cnt == modeNum ){
        cout << ll->head->val << ' ';
        ll->head = ll->head->next;
    }
    
    return 0;
}
