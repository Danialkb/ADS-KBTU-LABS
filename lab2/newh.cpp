#include <bits/stdc++.h>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int &p){
    if(!head && p == 0)head = node;
    else if(p == 0){
        node->next = head;
        head = node;
    }
    else{
        Node *cur = head;
        for(int i = 0; i < p - 1; i++)cur = cur->next;
        node->next = cur->next;
        cur->next = node;
    }
    return head;
}
 
Node* remove(Node* head, int &p){
    if(p == 0){
        head = head->next;
    }
    else{
        Node *cur = head;
        for(int i = 0; i < p - 1; i++)cur = cur->next;
        cur->next = cur->next->next;
    }
    return head;
}
 
Node* replace(Node* head, int &p1, int &p2){
    Node *cur = head;
    for(int i = 0; i < p1; i++)cur = cur->next;
    Node *tmp = new Node(cur->val);
    head = remove(head, p1);
    head = insert(head, tmp, p2);
    return head;
}
 
Node* reverse(Node* head){
    Node *cur = head;
    Node *prev = NULL;
    Node *next = NULL;
    while(cur){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
 
void print(Node* head){
    Node *cur = head;
    while(cur){
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
}
 
int sizeofll(Node* head){
     Node *forsize = head;
    int size = 0;
    while(forsize){
        size++;
        forsize = forsize->next;
    }
    return size;
}
Node* cyclic_left(Node* head, int &k){
    int size = sizeofll(head);
    if(size == k || k == 0)return head;
    Node *cur = head;
    Node *tmp = head;
    for(int i = 0; i < k - 1; i++){
        cur = cur->next;
    }
    head = cur->next;
    cur->next = nullptr;
    Node *newhead = head;
    while(newhead->next)newhead = newhead->next;
    newhead->next = tmp;

    return head;
}
Node* cyclic_right(Node* head, int &k){
    int size = sizeofll(head);
    if(size == k || k == 0)return head;
    int n = (size - k);
    head = cyclic_left(head, n);
    return head;
}
 
int main(){
    // freopen ("input.txt" , "r", stdin);
    // freopen ("output.txt" , "w", stdout);
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}