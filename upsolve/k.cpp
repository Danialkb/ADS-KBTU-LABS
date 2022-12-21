#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *next;
    Node *prev;
    Node(){
        this->val = 0;
        this->next = nullptr;
    }
    Node(int val){
        this->val = val;
        this->next = nullptr;
    }
};
struct DoublyLinkedList{
    Node *head;
    Node *tail;
    DoublyLinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    void push_front(int val){
        Node *tmp = new Node(val);
        if(!this->head){
            this->head = tmp;
            this->tail = tmp;
        }
        else{
            tmp->next = this->head;
            this->head->prev = tmp;
            this->head = tmp;
        }
    }
    void push_back(int val){
        Node *tmp = new Node(val);
        if(!this->head){
            this->head = tmp;
            this->tail = tmp;
        }
        else{
            tmp->prev = this->tail;
            this->tail->next = tmp;
            this->tail = tmp;
        }
    }
    void print(int n){
        if(n%2 == 0){
            Node* cur = this->head;
            while(cur){
                cout << cur->val << ' ';
                cur = cur->next;
            }
            cout << endl;
        }
        else{
            Node* cur = this->tail;
            while(cur){
                cout << cur->val << ' ';
                cur = cur->prev;
            }
            cout << endl;
        }
    }
};
int main() {
    DoublyLinkedList dll;
    int n;
    cin >> n;
    int cnt = 0;
    while(n--){
        int x;
        cin >> x;
        if(x == 1){
            int tmp;
            cin >> tmp;
            if(cnt % 2 == 0)dll.push_back(tmp);
            else dll.push_front(tmp);
        }else{
            cnt++;
        }
    }
    dll.print(cnt);
    return 0;
}