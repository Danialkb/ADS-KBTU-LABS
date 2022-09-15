#include <bits/stdc++.h>
using namespace std;
struct Node{
    string val;
    Node *next;
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
    Node *head;
    int size;
    LinkedList(){
        this->head = nullptr;
        this->size = 0;
    }
    void push_back(string val){
        if(!this->head){
            this->head = new Node(val);
            this->size++;
        }
        else {
            Node *cur = this->head;
            while(cur->next){
                if(cur->val == val){
                    return;
                }
                cur = cur->next;
            }
            if(cur->val == val){
                    return;
            }
            cur->next = new Node(val);
            this->size++;
        }
    }

    void print(){
        Node *cur = this->head;
        while(cur){
            cur = cur->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList *ll = new LinkedList();
    int n;
    string a;
    cin >> n;
    while(n--){
        cin >> a;
        ll->push_back(a);
    }
    cout << "All in all: " << ll->size << endl << "Students:\n";
    vector<string> res;
    while(ll->head){
        res.push_back(ll->head->val);
        ll->head = ll->head->next;
    }
    for(int i = res.size() - 1; i >= 0; i--)cout << res[i] << endl;

    return 0;
}