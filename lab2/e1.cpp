#include <bits/stdc++.h>

using namespace std; 

class Node  
{  
    public: 
    string data;  
    Node* next;  
};  
  
void removeDuplicates(Node** head)  
{  
    Node *cur = *head;
    Node *tmp = new Node();
    Node *res = tmp;
    while(cur){
        if(cur->next && cur->data == cur->next->data){
            Node *node = cur;
            cur = cur->next;
            delete(node);
        }else{
            tmp->next = cur;
            cur = cur->next;
            tmp = tmp->next;
        }
    }
    tmp->next = NULL;
    *head= res->next;
}  

int getCount(Node* head)  
{  
    int count = 0; 
    Node *cur = head;
    while(cur){
        count++;
        cur = cur->next;
    }
    return count;  
}  

void push(Node** head_ref, string new_data)  
{  

    Node* new_node = new Node(); 
              

    new_node->data = new_data;  
                  

    new_node->next = (*head_ref);      
          

    (*head_ref) = new_node;  
}  
 

void printList(Node *node)  
{  
    while (node!=NULL)  
    {  
        cout<<node->data<<"\n";  
        node = node->next;  
    }  
}  

int main()  
{  
    int n;
    string s;
    cin>>n;
    Node* head = NULL;  
    for(int i =0;i<n;i++){
        cin>>s;
        push(&head,s);
    }
                                      
    removeDuplicates(&head);  
    cout<<"All in all: "<<getCount(head);
  
    cout<<"\nStudents:\n";      
    printList(head);              
  
    return 0;  
}