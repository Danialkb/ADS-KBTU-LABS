#include <bits/stdc++.h>
  
using namespace std;

struct Node{
	Node * prev;
	Node * next;
	string val;
	Node(string _val){
		prev = NULL;
		next = NULL;
		val = _val;
	}	
};

Node * head = NULL;
Node * tail = NULL;
int cnt;
void add_back(string s){
    Node *tmp = new Node(s);
    if(head == NULL){
        head = tmp;
        tail = tmp;
    }
    else{
        tail->next = tmp;
        tmp->prev = tail;
        tail = tmp;
    }
}
void add_front(string s){
    Node *tmp = new Node(s);
    if(head == NULL){
        head = tmp;
        tail = tmp;
    }
    else{
        tmp->next = head;
        head->prev = tmp;
        head = tmp;
    }
}
bool empty(){
    if(head != NULL)return false;
    return true;
}
void erase_front(){
    if(head == tail){
        head = NULL;
        tail = NULL;
    }
    else{
        head = head->next;
        head->prev = NULL;
    }
}
void erase_back(){
    if(head == tail){
        head = NULL;
        tail = NULL;
    }
    else{
        tail = tail->prev;
        tail->next = NULL;
    }
}
string front(){
    return head->val;
}
string back(){
    return tail->val;
}
void clear(){
    while(head)head = head->next;
}
void print(){
    Node *cur = head;
    while(cur){
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << endl;
}
int main()
{
    // freopen ("input.txt" , "r", stdin);
    // freopen ("output.txt" , "w", stdout);
	string s;
   	while(cin >> s){
   		if(s == "add_front"){
   			string t;
   			cin >> t;
   			add_front(t);
   			cout << "ok" << endl;
   		}
   		if(s == "add_back"){
   			string t;
   			cin >> t;
   			add_back(t);
   			cout << "ok" << endl;
   		}
   		if(s == "erase_front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else
   			{
   				cout << front() << endl;
   				erase_front();
   			}
   		}
   		if(s == "erase_back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   				erase_back();
   			}
   		}
   		if(s == "front"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << front() << endl;
   			}
   		}
   		if(s == "back"){
   			if(empty()){
   				cout << "error" << endl;
   			}
   			else{
   				cout << back() << endl;
   			}
   		}
   		if(s == "clear"){
   			clear();
   			cout << "ok" << endl;
   		}
   		if(s == "exit"){
   			cout << "goodbye" << endl;
   			break;
   		}
   		// print();
   	}
    return 0;
}