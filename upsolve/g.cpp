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
struct Queue{
    Node *head;
    Node *tail;
    int size;
    Queue(){
        this->head = nullptr;
        this->tail = nullptr;
        size = 0;
    }
    void push(int val){
        Node *tmp = new Node(val);
        if(!this->head){
            this->head = tmp;
            this->tail = tmp;
        }
        else {
            this->tail->next = tmp;
            this->tail = tmp;
        }
        size++;
    }
    int top(){
        return this->head->val;
    }
    void pop(){
        head = head->next;
        size--;
    }
    bool empty(){
        return head == nullptr;
    }
};
int main() {
    int n;
    cin >> n;
    Queue q;
    while(n--){
        int x;
        cin >> x;
        q.push(x);
        if(x > 3000){
            int tmp = x - 3000;
            while(!q.empty() && q.top() < tmp)q.pop();
        }
        cout << q.size << ' ';
    }

    return 0;
}
