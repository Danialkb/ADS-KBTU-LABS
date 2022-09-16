#include <bits/stdc++.h>
using namespace std;
vector<bool> chars(26, false);
struct Node{
    char val;
    Node *next;
    Node(char val){
        this->val = val;
        this->next = NULL;
    }
};
struct LinkedList{
    Node *head;
    Node *tail;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }
    void print(){
        Node *cur = head;
        while(cur){
            cout << cur->val << ' ';
            cur = cur->next;
        }
        cout << endl;
    }
    void push_back(char val){
        if(!this->head && !chars[val - 97]){
            Node *tmp = new Node(val);
            this->head = tmp;
            this->tail = tmp;
        }
        else if(this->head && this->head->val == val){
            this->head = this->head->next;
        }
        else{
            if(this->head){
                Node *cur = this->head;
                while(cur->next){
                    if(cur->val == val){
                        chars[val - 97] = true;
                        cur->next = cur->next->next;
                        return;
                    }
                    cur = cur->next;
                }
                if(cur->val == val){
                    chars[val - 97] = true;
                    Node *again = this->head;
                    while(again->next != this->tail)again = again->next;
                    this->tail = again;
                    again->next = NULL;
                }
                else{
                    Node *tmp = new Node(val);
                    this->tail->next = tmp;
                    this->tail = tmp;
                }
            }
        }
    }

    bool empty(){
        if(this->head != NULL)return false;
        return true;
    }
    
};
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    char a;
    cin >> n;
    for(int i = 0; i < n; i++){
        LinkedList *ll = new LinkedList();
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> a;
            if(!chars[a - 97])ll->push_back(a);
            // if(ll->empty())cout << "-1 ";
            // else {
            //     cout << ll->head->val << ' ';
            // }
        }
        ll->print();
        cout << endl;
        cout << chars[0];
    }

    return 0;
}