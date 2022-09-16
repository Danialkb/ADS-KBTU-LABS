#include <bits/stdc++.h>
using namespace std;
vector<bool> chars(26, false);
struct Node{
    char val;
    Node *next;
    bool visited;
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

    void push_back(char val){
        Node *tmp = new Node(val);
        if(!this->head){
            this->head = tmp;
            this->tail = tmp;
        }
        else{
            Node *cur = this->head;
            while(cur){
                if(cur->val == val){
                    cur->visited = true;
                    return;
                }
                cur = cur->next;
            }
            this->tail->next = tmp;
            this->tail = tmp;
        }
    }
    // bool founded(char val){
    //     Node *cur = this->head;
    //     while(cur){
    //         if(cur->val == val){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    bool empty(){
        if(this->head != NULL)return false;
        return true;
    }
    
};
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, k;
    char a;
    cin >> n;
    for(int i = 0; i < n; i++){
        LinkedList *ll = new LinkedList();
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> a;
            bool founded = false;
            ll->push_back(a);
            Node *tmp = ll->head;
            while(tmp){
                if(tmp->visited == false){
                    cout << tmp->val << ' ';
                    founded = true;
                    break;
                }
                tmp = tmp->next;
            }
            if(!founded)cout << "-1 ";
        }
        cout << endl;
    }

    return 0;
}