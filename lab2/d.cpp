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
    int mode(){
        Node *cur = this->head;
        int max1 = -1e9;
        while(cur){
            if(cur->cnt > max1)max1=cur->cnt;
            cur = cur->next;
        }
        return max1;
    }
    void print(){
        Node *cur = this->head;
        while(cur){
            cout << cur->cnt << ' ';
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
    int maxOfLL = ll->mode();
    while(ll->head){
        if(ll->head->cnt == maxOfLL){
            cout << ll->head->val << ' ';
        }
        ll->head = ll->head->next;
    }
    return 0;
}