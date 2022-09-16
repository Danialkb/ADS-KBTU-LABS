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
    Node* head;
    Node *tail;
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
    int maxsum = ll->head->val;
    int sum = 0;
    while(ll->head){
        sum += ll->head->val;
        if(sum > maxsum)maxsum = sum;
        if(sum < 0)sum = 0;
        ll->head = ll->head->next;
    }
    cout << maxsum << endl;
    return 0;
}