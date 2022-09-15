#include <bits/stdc++.h>
using namespace std;
struct Node{
    string val;
    Node* next;
    Node(){
        this->val = "";
        this->next = NULL;
    }
    Node(string val){
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
    void push_front(string val){
        Node *tmp = new Node(val);
        if(!this->head){
            this->head = tmp;
            this->tail = tmp;
        }
        else{
            this->head->next = tmp;
            this->head = tmp;
        }
    }
    void push_back(string val){
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
    void erase_front(){
        this->head = this->head->next;
    }
    void erase_back(){
        Node *cur = head;
        while(cur->next)cur = cur->next;
        this->tail = cur;
        cur->next = cur->next->next;
    }

};
int main() {
    LinkedList *ll = new LinkedList();
    string s;
    while(cin >> s){
        if(s == "exit"){
            cout << endl;
            return 0;
        }
        else if(s == "add_front"){
            string t;
            cin >> t;
            ll->push_front(t);
            cout << "ok\n";
        }
        else if(s == "add_back"){
            string t;
            cin >> t;
            ll->push_back(t);
            cout << "ok\n";
        }
        else if(s == "erase_front"){
            string t;
            cin >> t;
            cout << ll->head->val << endl;
            ll->erase_front();
        }
        else if(s == "erase_back"){
            string t;
            cin >> t;
            cout << ll->tail->val << endl;
            ll->erase_back();
        }
        else if(s == "front")cout << ll->head->val << endl;
        else if(s == "back")cout << ll->tail->val << endl;
        else{
            while(ll->head != ll->tail)ll->head = ll->head->next;
        }
    }
    return 0;
}
