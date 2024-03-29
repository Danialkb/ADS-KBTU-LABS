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
struct Stack{
    Node* head;
    Stack(){
        this->head = nullptr;
    }
    void add(int val){
        Node* tmp = new Node(val);
        if(!head){
            this->head = tmp;
        }
        else{
            tmp->next = this->head;
            this->head = tmp;
        }
    }
    int top(){
        return this->head->val;
    }

    void pop(){
        if(!empty())head = head->next;
    }

    bool empty(){
        return this->head == nullptr;
    }

    int getnewMax(){
        Node* cur = this->head;
        int newmx = -1e9;
        while(cur){
            if(cur->val > newmx)newmx = cur->val;
            cur = cur->next;
        }
        return newmx;
    }

};



int main() {
    // freopen ("input.txt" , "r", stdin);
    // freopen ("output.txt" , "w", stdout);
    Stack st;
    int n;
    cin >> n;
    string s;
    int mx = -1e9;
    while(n--){
        cin >> s;
        if(s == "add"){
            int x;
            cin >> x;
            st.add(x);
            if(st.top() > mx)mx = x;
        }
        if(s == "delete"){
            if(st.top() == mx){
                st.pop();
                mx = st.getnewMax();
            }
            else st.pop();
        }
        if(s == "getcur"){
            if(!st.empty())cout << st.top() << endl;
            else cout << "error\n";
        }
        if(s == "getmax"){
            if(!st.empty())cout << mx << endl;
            else cout << "error\n";
        }
    }

    return 0;
}