#include <bits/stdc++.h>
using namespace std;
bool comparator(pair<int, int> &p1, pair<int, int> &p2){
    if(p1.second == p2.second)return p1.first > p2.first;
    return p1.second > p2.second;
}
struct Node{
    int val;
    int cnt;
    Node *next;
    Node(){
        this->val = 0;
        this->next = NULL;
        this->cnt = 1;
    }
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->cnt = 1;
    }
};
struct LinkedList{
    Node *head;
    int size;
    LinkedList(){
        this->head = nullptr;
        this->size = 0;
    }
    void push_back(int val){
        if(!this->head){
            this->head = new Node(val);
            this->size++;
        }
        else {
            Node *cur = this->head;
            while(cur->next){
                if(cur->val == val){
                    cur->cnt++;
                    return;
                }
                cur = cur->next;
            }
            if(cur->val == val){
                    cur->cnt++;
                    return;
            }
            cur->next = new Node(val);

        }
    }
    void mode(){
        Node *cur = this->head;
        vector<pair<int, int> > res;
        while(cur){
            res.push_back(make_pair(cur->val, cur->cnt));
            cur = cur->next;
        }
        sort(res.begin(), res.end(), comparator);
        for(int i = 0; i < res.size(); i++){
            if(res[i].second == res[0].second)cout << res[i].first << ' ';
        }
    }
};
int main() {
    LinkedList *ll = new LinkedList();
    int n, a;
    cin >> n;
    while(n--){
        cin >> a;
        ll->push_back(a);
    }
    ll->mode();
    
    return 0;
}