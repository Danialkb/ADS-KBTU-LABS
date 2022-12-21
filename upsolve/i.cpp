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
    Node *top;
    int size;
    Stack(){ 
        this->top = nullptr;
        this->size = 0;
    }
    void push(int val){
        this->size++;
        if(this->empty()){
            this->top = new Node(val);
        }
        else{
            Node *tmp = new Node(val);
            tmp->next = this->top;
            this->top = tmp;
        }
    }
    
    void pop(){
        this->size--;
        Node *toDel = top;
        top = top->next;
        delete(toDel);
    }

    int peek(){
        return this->top->val;
    }

    bool empty(){
        return this->size == 0;
    }

};

string check(string s){
    Stack st;
    for(int i= 0; i < s.size(); i++){
        if(!st.empty() && st.peek() == 0 && s[i] == '1')st.pop();
        else st.push(s[i] - 48);
    }
    if(st.empty())return "YES\n";
    return "NO\n";
}

int main() {
    int n;
    cin >> n;
    while(n--){
        long long x;
        cin >> x;
        string s;
        while(x != 0){
            s += char(x%2 + 48);
            x /= 2;
        }
        cout << check(s);
    }

    return 0;
}