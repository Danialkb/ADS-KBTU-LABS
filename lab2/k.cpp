#include <bits/stdc++.h>
using namespace std;
struct Node{
    char val;
    Node *next;
    Node(char val){
        this->val = val;
        this->next = NULL;
    }
};
struct LinkedList{
    Node* head;
    Node *tail;
    LinkedList(){
        this->head = NULL;
    }

    void push_back(char val){
        Node* tmp = new Node(val);
        if(!this->head){
            this->head = tmp;
            this->tail = tmp;
        }
        else if(this->head->val == tmp->val){
            this->head = this->head->next;
            return;
        }
        else{
            this->tail->next = tmp;
            this->tail = tmp;
        }
    }

    bool empty(){
        if(this->head != NULL)return true;
        else return false;
    }
    
};
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    LinkedList *ll = new LinkedList();
    int n, k;
    char a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        vector<string> res;
        for(int j = 0; j < k; j++){
            cin >> a;
            ll->push_back(a);
            if(ll->empty())res.push_back("-1");
            else {
                string temp = "";
                temp += ll->head->val;
                res.push_back(temp);
            }
        }
        for(int p = 0; p < res.size(); p++){
            cout << res[p] << ' ';
        }
        cout << endl;
    }

    return 0;
}