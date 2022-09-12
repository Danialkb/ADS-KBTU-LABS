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
    Node* head;
    Node* tail;
    LinkedList(){
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
    }
    int getNearest(int k){
        Node *cur = this->head;
        int min = 1e9, minpos = -1, cnt = 0;
        while(cur){
            if((abs(k - cur->val)) < min){
                min = abs(k - cur->val);
                minpos = cnt;
            }
            cur = cur->next;
            cnt++;
        }
        return minpos;
    }
};
int main() {
    LinkedList *ll = new LinkedList();
    int n, k;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        ll->push_back(a);
    }
    cin >> k;
    cout << ll->getNearest(k) << endl; 
    return 0;
}
